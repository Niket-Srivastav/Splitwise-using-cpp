#include <bits/stdc++.h>
using namespace std;

int main(){
    long long friends;
    cout<<"Enter the number of friends"<<"\n";
    cin>>friends;
    cout<<"Enter the names of friends(if two friends have same name enter with numberals as Rahul1 and Rahul2)"<<"\n";
    
    map<string,long long> net;

    for(long long i=1;i<=friends;i++){
        cout<<"Enter the name of friend "<<i<<"\n";
        string fr;
        cin>>fr;
        net[fr]=0;
    }
    
    long long no_of_transaction;
    cout<<"Enter the number of transaction"<<"\n";
    cin>>no_of_transaction;

    for(long long i=1;i<=no_of_transaction;i++){

        string debiter,crediter;
        cout<<"details of transaction"<<i<<"\n";
        cout<<"Enter the name of debiter"<<"\n";
        cin>>debiter;
        cout<<"Enter the name of crediter"<<"\n";
        cin>>crediter;
        long long amount;
        cout<<"Enter the amount"<<"\n";
        cin>>amount;
        net[debiter]-=amount;
        net[crediter]+=amount;
        cout<<"------------------------------------------------------------------\n";
        cout<<"\n";

    }

    multiset<pair<long long,string>> mp;

    for(auto e:net){
        string person=e.first;
        long long net_amount=e.second;
        if(net_amount!=0){
            mp.insert({net_amount,person});
        }
    }


    long long mn_transaction=0;
    while(!mp.empty()){
        auto low=mp.begin();
        auto high=mp.end();
        high--;

        long long deb_amount=low->first;
        long long cred_amount=high->first;

        string deb_person=low->second;
        string cred_person=high->second;

        mp.erase(low);
        mp.erase(high);

        long long pay=min(abs(deb_amount),cred_amount);

        deb_amount+=pay;

        cred_amount-=pay;

        cout<<deb_person<<" will pay "<<pay<<" to "<<cred_person<<"\n";
        
        mn_transaction++;

        if(deb_amount!=0){
            mp.insert({deb_amount,deb_person});
        }
        
        if(cred_amount!=0){
            mp.insert({cred_amount,cred_person});
        }
    }

    cout<<"minimum number of transaction "<<mn_transaction<<"\n";
}