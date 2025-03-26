#include "../Vector/Vector/Vector.h"

using namespace std;

int main()
{
    try
    {
        Vector<int> vec(5);
        vec.setElem(0, 1);
        vec.setElem(1, 2);
        vec.setElem(2, 3);
        vec.setElem(3, 4);
        vec.setElem(4, 5);

        cout << "Vector: " << vec << endl;

        cout << "Iterator test:" << endl;
        for (auto it = vec.begin(); it != vec.end(); ++it) 
        {
            cout << *it << " ";
        }
        cout << endl;

        Vector<int> vec_copy(vec);
        cout << "Copied Vector: " << vec_copy << endl;

        Vector<int> vec_move(move(vec_copy));
        cout << "Moved Vector: " << vec_move << endl;

        Vector<int> vec_init = { 6, 7, 8, 9, 10 };
        cout << "Initialized Vector: " << vec_init << endl;

        vec += vec_init;
        cout << "After +=: " << vec << endl;

        vec -= vec_init;
        cout << "After -=: " << vec << endl;

        vec *= 2;
        cout << "After *=: " << vec << endl;

        vec /= 2;
        cout << "After /=: " << vec << endl;

        Vector<int> vec_sum = vec + vec_init;
        cout << "vec + vec_init: " << vec_sum << endl;

        Vector<int> vec_diff = vec - vec_init;
        cout << "vec - vec_init: " << vec_diff << endl;

        Vector<int> vec_mul = vec * 2;
        cout << "vec * 2: " << vec_mul << endl;

        Vector<int> vec_div = vec / 2;
        cout << "vec / 2: " << vec_div << endl;

    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
