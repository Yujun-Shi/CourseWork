//
// created by Yujun Shi
//

int n;

void fibs(int n) {
    int res = 1;
    int pingpong = 1;
    for (int i = 0; i < n; ++i) {
        int t = res;
        res += pingpong;
        pingpong = t;
        if (i < 3 || i > 5 && i < 7) {
            print(1);
        }
        else {
            print(n);
        }
    }
}

void main()
{
    input(n);
    n *= 2;
    fibs(n);
}
