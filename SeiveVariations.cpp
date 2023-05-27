const int N = 1e6 + 7 ;
vector<int> isPrime(N,true);

void seive(){
     isPrime[0] = isPrime[1] = false ;
     for(int i = 2 ; i < N ; ++i){
         if(isPrime[i]){
             for(int j = i*i ; j < N ; j+=i){
                isPrime[j] = false ;
             }
         }
     }
}

vector<int> lowestPrime(N,N) ;
void seiveLPF(){
    isPrime[0] = isPrime[1] = false ;
     int n = isPrime.size();
    for(int i=0 ; i<n ; ++i){
        lowestPrime[i] = i ;
    }
     for(int i = 2 ; i < N ; ++i){
         if(isPrime[i]){
             for(int j = i*i ; j < N ; j+=i){
                isPrime[j] = false ;
                if(lowestPrime[j] == j){
                    lowestPrime[j] = i ;
                }
             }
         }
     }
}

vector<int> PrimeFactors(int num){
    vector<int> primes ;
    while(num > 1){
        primes.pb(lowestPrime[num]);
        num = num/lowestPrime[num];
    }
    return primes ;
}
