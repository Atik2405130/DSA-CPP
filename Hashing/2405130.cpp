#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <iomanip>
#include <utility>

using namespace std;

const int initial_size = 13; 
const double upper_load_factor = 0.5;
const double lower_load_factor = 0.25;

int check_prime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int next_prime(int x)
{
    int next_possible_prime = x + 1;
    while (!check_prime(next_possible_prime))
    {
        next_possible_prime++;
    }
    return next_possible_prime;
}

int previous_prime(int x)
{
    int prev_possible_prime = x - 1;
    while (prev_possible_prime > initial_size)
    {
        if (check_prime(prev_possible_prime))
            return prev_possible_prime;
        else
            prev_possible_prime--;
    }
    return initial_size;
}

string random_word_generator(int len)
{
    string random_word = "";
    for (int i = 0; i < len; i++)
    {
        char random_letter = 'a' + (rand() % 26);
        random_word += random_letter;
    }
    return random_word;
}

enum Method
{
    CHAINING,
    DOUBLE_HASHING,
    CUSTOM_PROBING
};
enum State
{
    EMPTY,
    OCCUPIED,
    DELETED
};

const int C1 = 1;
const int C2 = 1;

template <typename Key, typename Value>
struct HashNode
{
    Key key;
    Value value;
    State state = EMPTY;
};

// Polynomial Rolling Hash
unsigned long hash1(const string &key)
{
    unsigned long h = 0;
    for (char c : key)
        h = h * 31 + (c - 'a' + 1);
    return h;
}

// DJB2 Hash
unsigned long hash2(const string &key)
{
    unsigned long h = 5381;
    for (char c : key)
        h = ((h << 5) + h) + c;
    return h;
}

// Auxiliary Hash Function
unsigned long auxHash(const string &key, int N)
{
    return 1 + (hash1(key) % (N - 1));
}

template <typename Key, typename Value>
class HashTable
{
    Method method;
    int hashType;
    int capacity;
    int count;

    int elements_at_last_resize;
    int insertions_since_resize;
    int deletions_since_resize;

    vector<list<pair<Key, Value>>> chain_table;
    vector<HashNode<Key, Value>> open_table;

    unsigned long get_primary_hash(const Key &key)
    {
        return (hashType == 1 ? hash1(key) : hash2(key)) % capacity;
    }

    int probe_idx(const Key &key, int i)
    {
        unsigned long h = get_primary_hash(key);
        unsigned long a = auxHash(key, capacity);
        if (method == DOUBLE_HASHING)
        {
            return (h + (long long)i * a) % capacity;
        }
        else
        {
            return (h + (long long)C1 * i * a + (long long)C2 * i * i) % capacity; //custom probing
        }
    }

    void resize(int new_capacity)
    {
        capacity = new_capacity;

        elements_at_last_resize = count;
        insertions_since_resize = 0;
        deletions_since_resize = 0;

        if (method == CHAINING)
        {
            vector<list<pair<Key, Value>>> old_chain = std::move(chain_table);
            chain_table.assign(capacity, list<pair<Key, Value>>());

            for (const auto &bucket : old_chain)
            {
                for (const auto &bkt : bucket)
                {
                    int idx = get_primary_hash(bkt.first);
                    chain_table[idx].push_back(bkt);
                }
            }
        }
        else
        {
            vector<HashNode<Key, Value>> old_open = std::move(open_table);
            open_table.assign(capacity, HashNode<Key, Value>());

            for (const auto &node : old_open)
            {
                if (node.state == OCCUPIED)
                {
                    for (int i = 0; i < capacity; i++)
                    {
                        int idx = probe_idx(node.key, i);
                        if (open_table[idx].state != OCCUPIED)
                        {
                            open_table[idx] = {node.key, node.value, OCCUPIED};
                            break;
                        }
                    }
                }
            }
        }
    }

public:
    long long collisions = 0;
    long long collision_free = 0;

    HashTable(Method m, int hashType)
    {
        method = m;
        this->hashType = hashType;
        capacity = initial_size;
        count = 0;
        elements_at_last_resize = initial_size;
        insertions_since_resize = 0;
        deletions_since_resize = 0;
        if (method == CHAINING)
            chain_table.resize(capacity);
        else
            open_table.resize(capacity);
    }

    void insert(const Key &key, Value value)
    {
        if (method == CHAINING)
        {
            int idx = get_primary_hash(key);
            if (!chain_table[idx].empty())
            {
                collisions++; // bucket already contains elements
            }
            else
            {
                collision_free++;
            }
            chain_table[idx].push_back({key, value});
        }
        else
        {
            bool inserted = false;
            bool hit_collision = false;
            for (int i = 0; i < capacity; i++)
            {
                int idx = probe_idx(key, i);
                if (open_table[idx].state == OCCUPIED)
                {
                    collisions++; // probe lands on an occupied slot
                    hit_collision = true;
                }
                else
                {
                    open_table[idx] = {key, value, OCCUPIED};
                    if (!hit_collision)
                        collision_free++;
                    inserted = true;
                    break;
                }
            }
            if (!inserted)
                return;
        }

        count++;
        insertions_since_resize++;
        double load_factor = (double)count / capacity;
        if (load_factor > upper_load_factor && insertions_since_resize >= elements_at_last_resize / 2)
        {
            resize(next_prime(2 * capacity));
        }
    }

    bool remove(const Key &key)
    {
        int found = -1;
        if (method == CHAINING)
        {
            int idx = get_primary_hash(key);
            for (auto it = chain_table[idx].begin(); it != chain_table[idx].end(); it++)
            {
                if (it->first == key)
                {
                    chain_table[idx].erase(it);
                    found = idx;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < capacity; i++)
            {
                int idx = probe_idx(key, i);
                if (open_table[idx].state == EMPTY)
                    break;
                if (open_table[idx].state == OCCUPIED && open_table[idx].key == key)
                {
                    open_table[idx].state = DELETED;
                    found = idx;
                    break;
                }
            }
        }
        if (found == -1)
            return false;
        count--;
        deletions_since_resize++;
        double load_factor = (double)count / capacity;
        if (load_factor < lower_load_factor && capacity > initial_size && deletions_since_resize >= elements_at_last_resize / 2)
        {
            resize(previous_prime(capacity / 2));
        }
        return true;
    }

    Value search(const Key &key, long long &hits)
    {
        hits = 0;
        if (method == CHAINING)
        {
            int idx = get_primary_hash(key);
            for (const auto &k : chain_table[idx])
            {
                hits++;
                if (k.first == key)
                    return k.second;
            }
        }
        else
        {
            for (int i = 0; i < capacity; i++)
            {
                hits++;
                int idx = probe_idx(key, i);
                if (open_table[idx].state == EMPTY)
                    return -1;
                if (open_table[idx].state == OCCUPIED && open_table[idx].key == key)
                    return open_table[idx].value;
            }
        }
        return -1;
    }
};

int main()
{
    srand(time(0));
    const int NUM_ENTRIES = 10000;
    const int SEARCH_SAMPLES = 1000;
    const int WORD_LEN = 10;

    vector<string> unique_words;
    unordered_set<string> seen;

    while (unique_words.size() < NUM_ENTRIES)
    {
        string s = random_word_generator(WORD_LEN);
        if (seen.insert(s).second)
        {
            unique_words.push_back(s);
        }
    }

    vector<string> search_samples;
    for (int i = 0; i < SEARCH_SAMPLES; i++)
    {
        search_samples.push_back(unique_words[rand() % NUM_ENTRIES]);
    }
    Method methods[] = {CHAINING, DOUBLE_HASHING, CUSTOM_PROBING};
    string method_names[] = {"Chaining Method", "Double Hashing", "Custom Probing"};

    cout << left << setw(18) << " "
         << " | Hash1" << setw(17) << " "
         << " | Hash2" << "\n";
    cout << left << setw(18) << "Method"
         << " | Collisions" << setw(4) << " " << "Avg Hits"
         << " | Collisions" << setw(4) << " " << "Avg Hits\n";
    cout << string(75, '-') << "\n";

    for (int m = 0; m < 3; m++)
    {
        HashTable<string, int> ht1(methods[m], 1); //hash 1
        HashTable<string, int> ht2(methods[m], 2); //hash 2

        for (int i = 0; i < NUM_ENTRIES; i++)
        {
            ht1.insert(unique_words[i], i + 1);
            ht2.insert(unique_words[i], i + 1);
        }
        long long hits1_sum = 0, hits2_sum = 0, current_hits = 0;
        for (const string &word : search_samples)
        {
            ht1.search(word, current_hits);
            hits1_sum += current_hits;

            ht2.search(word, current_hits);
            hits2_sum += current_hits;
        }
        cout << left << setw(18) << method_names[m]
             << " | " << setw(10) << ht1.collisions
             << "   " << fixed << setprecision(3) << setw(8) << (double)hits1_sum / SEARCH_SAMPLES
             << " | " << setw(10) << ht2.collisions
             << "   " << fixed << setprecision(3) << setw(8) << (double)hits2_sum / SEARCH_SAMPLES << "\n";
    }

    cout << string(75, '-') << "\n";
}