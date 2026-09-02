#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<ll>> v(x, vector<int>(y))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define tata "\n"
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *cur = nullptr;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode(sum % 10);
            if (!head)
            {
                head = cur = node;
            }
            else
            {
                cur->next = node;
                cur = cur->next;
            }
            carry = sum / 10;
        }
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n;
        vector<int> v1(n);
        in(v1);
        cin >> m;
        vector<int> v2(m);
        in(v2);
        // Build l1
        ListNode *l1 = nullptr, *tail1 = nullptr;
        for (int x : v1)
        {
            if (!l1)
                l1 = tail1 = new ListNode(x);
            else
            {
                tail1->next = new ListNode(x);
                tail1 = tail1->next;
            }
        }
        // Build l2
        ListNode *l2 = nullptr, *tail2 = nullptr;
        for (int x : v2)
        {
            if (!l2)
                l2 = tail2 = new ListNode(x);
            else
            {
                tail2->next = new ListNode(x);
                tail2 = tail2->next;
            }
        }
        Solution obj;
        ListNode *res = obj.addTwoNumbers(l1, l2);
        // Output result
        while (res)
        {
            cout << res->val << " ";
            res = res->next;
        }
        cout << endl;
    }
    return 0;
}