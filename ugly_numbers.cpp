#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

unsigned getNthUglyNumber(unsigned n){
	unsigned ugly[n], next_ugly_number;
	ugly[0]=1;
	unsigned i2=0, i3=0, i5=0;
	unsigned next_mulitple_of_2 = ugly[i2]*2;
	unsigned next_mulitple_of_3 = ugly[i3]*3;
	unsigned next_mulitple_of_5 = ugly[i5]*5;

	for(int i=1; i<n; i++){
		next_ugly_number = min({next_mulitple_of_2, next_mulitple_of_3, next_mulitple_of_5});
		ugly[i] = next_ugly_number;

		if(next_ugly_number == next_mulitple_of_2){
			i2 +=1;
			next_mulitple_of_2 = ugly[i2]*2;
		}
		if(next_ugly_number == next_mulitple_of_3){
			i3 +=1;
			next_mulitple_of_3 = ugly[i3]*3;
		}
		if(next_ugly_number == next_mulitple_of_5){
			i5 +=1;
			next_mulitple_of_5 = ugly[i5]*5;
		}
	}
	return next_ugly_number;
}

int main()
{
	/* code */
	int n;
	cin>>n;
	cout<<getNthUglyNumber(n);
	return 0;
}