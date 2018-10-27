#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdlib>

using namespace std;


bool isPrime[1000001];
vector<int> primes;

void sieve() {
	memset(isPrime,true,sizeof(isPrime));
	for (int p=2; p*p<=1000000; p++) { 
        if (isPrime[p]) { 
            for (int i=p*2;i<=1000000;i+=p) 
                isPrime[i] = false; 
        } 
    } 

    // store primes
    for(int i=2;i<=1000000;i++)
    	if(isPrime[i])
    		primes.push_back(i);
}


int getRem(string s, int num) {
	int rem = 0;
	for(int i=0;i<s.length();i++) {
		rem=((rem*10) + (s[i]-'0'))%num;
		rem%=num;
	}
	return rem;
}

int getPrime(string num) {
	int low = 0;
	int high = primes.size();
	int mid;
	int idx;

	while(low<=high) {
		mid = low + (high-low)/2;
		if(getRem(num,primes[mid]) == 0) {
			low = mid+1;
			idx = mid;
		} else {
			high = mid-1;	
		}
	}
	return primes[idx];
}

// Factorial
int multiply(int x, int res[], int res_size)  { 
    int carry = 0; 
    for (int i=0; i<res_size; i++)  { 
        int prod = res[i] * x + carry;  
        res[i] = prod % 10;   
        carry  = prod/10;     
    } 
  
    while (carry) { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
}

string factorial(int n) { 
    int res[1000100]; 
  
    res[0] = 1; 
    int res_size = 1; 
  
    for(int x=2; x<=n; x++) 
        res_size = multiply(x, res, res_size); 
  
  	string ans = "";
    
    for(int i=res_size-1; i>=0; i--) 
        ans+=to_string(res[i]);

    return ans; 
} 


int main() {
	sieve();
	string num;
	cin>>num;

	//cout<<getRem(num,21)<<endl;
	int pPrime = getPrime(num);
	//cout<<pPrime<<endl;	
	//cout<<factorial(5)<<endl;
	int ans = pPrime;
	
	while(1) {
		if(factorial(ans)==num) {
			break;
		}
		ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}