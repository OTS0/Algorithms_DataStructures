#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class List
{
    vector<int> v; // Our tree, indexed like a heap
    int size, bottom, step, current, remains;

    // Calculates the next power of 2 equal or bigger to x
    //uses to resize vector
    inline int nextpow(int x)
    {
        x--;
        for (int i = 1; i <= 16; i *= 2)
            x |= x >> i;
        return x + 1;
    }

    //Calculates multiplicity of 2 (count numbers of multiplicity of 2)
    int log(int x)
    {
        int ret = 0;
        while (x /= 2)
            ret++;
        return ret;
    }
    //Calculates a power of 2
    inline int pow2(int n)
    {
        int ret = 1;
        while (n-- > 0)
            ret *= 2;
        return ret;
    }

    inline int parent(const int& node) const
    {
        return node / 2;
    }

    inline int rightchild(const int& node) const
    {
        return node * 2 + 1;
    }

    inline int leftchild(const int& node) const
    {
        return node * 2;
    }

    inline bool intree(const int& node) const
    {
        return node <= bottom + size && node > 0;
    }

public:
    List(int n, int step) : size(n), step(step), current(step), remains(n)
    {
        v.resize(nextpow(n * 2));//change size the v
        int height = log(n * 2 - 1);
        bottom = pow2(height) - 1; // The node immediately preceding the first leaf

        for (int i = bottom + 1; i <= bottom + n; i++) // Leafs have key 1
            v[i] = 1;
        for (int i = bottom; i >= 1; i--) // Internal nodes' keys are the sum their childrens keys
            v[i] = (intree(leftchild(i)) ? v[leftchild(i)] : 0)
            + (intree(rightchild(i)) ? v[rightchild(i)] : 0);
    }
    //finding (availability) element for cycle
    int remaining()
    {
        return remains;
    }

    int getNext()
    {
        if (remains-- == size) // We're already at the first one so we handle this one directly
            return current;

        int node = bottom + current;
        while (node) // Bubble up a subtraction through the tree
        {
            v[node]--;
            node = parent(node);
        }
        node = bottom + current;

        int k = step; // The remaining number of soldiers that we need to skip
        enum source { left, right, up }; // The direction we arrived from to a node
        source source = right;

        // Our main routine - start at a leaf, search our way through the tree until we have
        // skipped the number of soldiers that need to be skipped
        while (k)
        {
            int lc = leftchild(node);
            int rc = rightchild(node);
            if (source == up)
            {
                if (intree(lc) && k > v[lc]) // We can skip the entire left subtree
                {
                    k -= v[lc];
                    source = up;
                    node = rc;
                }
                else if (!intree(lc) && k == v[node]) // Final leaf found
                    k--;
                else // The answer lies in our left subtree, enter it
                {
                    source = up;
                    node = lc;
                }
            }
            else if (source == right) // Always go up when we've come from a right subtree
            {
                source = node == rightchild(parent(node)) ? right : left;
                node = parent(node);
            }
            else // Coming from the left
            {
                if (intree(rc) && k > v[rc]) // We can skip the entire subtree in this case
                {
                    source = node == rightchild(parent(node)) ? right : left;
                    k -= v[rc];
                    node = parent(node);
                }
                else // Our answer lies within the right subtree; we must pursue our destiny there
                {
                    node = rc;
                    source = up;
                }
            }
            if (!intree(node))    // This happens whenever we started somewhere and couldn't find k
            {                    // successors to the right of us in the tree - in this case, we
                node = bottom + 1; // wrap around from the leftmost soldier leaf
                k -= v[node];
                source = right;
            }
        }
        return current = node - bottom; // Transform from tree index to soldier number
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    List list(n, k);
    while (list.remaining())
    {
        int ans = list.getNext(); 
        // It's a faster way of printing a number than calling printf
        char s[9];
        int l = 0;
        while (ans)
        {
            s[l++] = ans % 10;
            ans /= 10;
        }
        while (l--)
            putc('0' + s[l], stdout);
        putc(' ', stdout);
    }
    return 0;
}
