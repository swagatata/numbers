#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) cout << (t) ;
#define pn(t) cout << (t) << endl ;
#define in(n) scanf("%d", &n);
#define fin(fptr, n) fscanf(fptr, "%d", n); 
#define outn(n) printf("%d", n);
#define outs(s) printf("%s", s);

int main() {
    FILE * input_fptr = fopen("input_reminders", "r");

    int T;
    fin(input_fptr, &T)
    outn(T)
    outs("\n")

    unsigned int nums[T];
    unsigned int rems[T];//reminders
    unsigned int sums[T];

    FOR(i, T) {
        fin(input_fptr, nums + i)
        outn(nums[i])
        outs(" ")
    }
    outs("\n")
    FOR(i, T) {
        fin(input_fptr, rems + i)
        outn(rems[i])
        outs(" ")
    }
    outs("\n")

    FOR(i, T) {
        sums[i] = rems[i];
    }
    
    unsigned int min_i;
    bool equalSums = false;

    while(true) {
        min_i = 0;
        equalSums = true;
        FOR(i, T) {
            if (sums[i] < sums[min_i]) {
                min_i = i;
                equalSums = false;
            }
            if (equalSums && (sums[i] != sums[min_i])) {
                equalSums = false;
            }
        }
        if (equalSums) {
            break;
        }
        sums[min_i] += nums[min_i];
    }

    outn(sums[0])
    outs("\n")
}
