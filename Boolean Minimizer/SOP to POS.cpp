#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string dec2bin(int a)
{
    string ans;
    if (a==0)
    {
        ans="0";
        return ans;
    }

    while (a>0)
    {
        ans=ans+to_string(a%2);
        a=a/2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int bin2dec(string a){
 int ans=0;
 int x=1;
 for (int i=a.length()-1;i>=0;i--){
    if (a[i]=='1'){
    ans+= x*(a[i]-'0');
    }
    x=x*2;
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input_Q3.2.txt", "r",stdin);
    freopen("output_Q3.txt", "w",stdout);
    #endif // ONLINE

    string in;
    cin>>in;
    //cout<<in<<endl;
    int n1;
    cin>>n1;
    //cout<<n1<<endl;
    char var[n1];
    int cc=0;
    map <char ,int> m1;
    for (int i=0;i<=n1;i++){
        cin>>var[i];
        m1[var[i]]=cc;
        cc+=1;
    }

    string outt,comma;
    cin>>outt;
    //cout<<out<<endl;
    int n2;
    cin>>n2;
    //cout<<n2<<endl;
    char output[n2];

    for (int i=0;i<=n2;i++){
        cin>>output[i];
        if (i!= n2-1 && i!=n2 )
            cin>>comma;
    }
    for (int i=0;i<n2;i++){
            int size_= pow(2,n1);
            int out[size_];
            string exp;
            getline(cin,exp);
            if (i==0)
                exp=exp.substr(2,exp.length()-2);
            else
                exp=exp.substr(3,exp.length()-2);
            //cout<<exp<<endl;
            int sop=exp.find('(');
            //cout<<sop<<endl;
            vector<string> vect;
            if (sop== -1){
                for (int e=0;e<size_;e++){
                out[e]=0;
                }
                string temp=exp;
                int j;
                int prev_=0;
                for (j=0;j<exp.length();j++){
                    if (temp[j]=='+'){
                        string vel=temp.substr(prev_,j-prev_ -1);
                        vect.push_back(vel);
                        prev_=j+2;
                    }
                }
                string vel=temp.substr(prev_,temp.length()-prev_);
                vect.push_back(vel);
                for (auto& elem : vect){
                    //cout<<elem<<endl;
                    string mint;
                    for (int k=0;k<n1;k++){
                        mint.push_back('3');
                    }
                    int aa=0;
                    int n=count (elem.begin(),elem.end(),'\'');
                    for (int s=0;s<elem.length()-n;s++){
                        char c=elem[aa];
                        int posi = m1[c];
                        //cout<<posi<<endl;
                        if (elem[aa+1]=='\''){
                            mint[posi]='0';
                            aa+=2;
                        }
                        else {
                            mint[posi]='1';
                            aa+=1;
                        }
                    }
                    int n4=count(mint.begin(),mint.end(),'3');
                    int n5=pow(2,n4);
                    string mintt[n5];
                    for (int k=0;k<n5;k+=1){
                        mintt[k]=mint;
                    }
                    int power=1;
                    for (int s=0;s<n1;s++){
                        int c=0;
                      if (mint[s]=='3'){
                            power*=2;
                            for (int t=0;t<power;t++){
                                for (int k=0;k<n5/power;k+=1){
                                    if (t%2==0){
                                        mintt[c][s]='1';
                                        //cout<<mintt[k][s]<<endl;
                                    }
                                    else{
                                        mintt[c][s]='0';
                                        //cout<<mintt[k][s]<<endl;
                                    }
                                    c+=1;
                                }
                            }
                        }
                    }
                    for (int k=0;k<n5;k+=1){
                        //cout<<mintt[k]<<" ";
                        int a=bin2dec(mintt[k]);
                        out[a]=1;
                    }
                }
            }
            else{
                for (int e=0;e<size_;e++){
                out[e]=1;
                }
                int prev=1 ;
                string temp=exp;
                for (int j=0;j<exp.length();j++){
                    if (temp[j]==')'){
                        string vel= temp.substr(prev,j-prev );
                        vect.push_back(vel);
                        prev=j+2;
                    }
               }
               for (auto elem : vect){
               // cout<<elem<<endl;
                string mint;
                    for (int k=0;k<n1;k++){
                        mint.push_back('3');
                    }
                    int aa=0;
                    int n=count (elem.begin(),elem.end(),'\'');
                    int p=count (elem.begin(),elem.end(),'+');
                    for (int s=0;s<n1;s++){
                        char c=elem[aa];
                        int posi = m1[c];
                        //cout<<posi<<endl;
                        if (elem[aa+1]=='\''){
                            mint[posi]='1';
                            aa+=1;
                        }
                        else {
                            mint[posi]='0';
                        }
                        aa+=4;
                    }
                    int n4=count(mint.begin(),mint.end(),'3');
                    int n5=pow(2,n4);
                    string mintt[n5];
                    for (int k=0;k<n5;k+=1){
                        mintt[k]=mint;
                    }
                    int power=1;
                    for (int s=0;s<n1;s++){
                        int c=0;
                      if (mint[s]=='3'){
                            power*=2;
                            for (int t=0;t<power;t++){
                                for (int k=0;k<n5/power;k+=1){
                                    if (t%2==0){
                                        mintt[c][s]='1';
                                        //cout<<mintt[k][s]<<endl;
                                    }
                                    else{
                                        mintt[c][s]='0';
                                        //cout<<mintt[k][s]<<endl;
                                    }
                                    c+=1;
                                }
                            }
                        }
                    }
                    for (int k=0;k<n5;k+=1){
                        //cout<<mintt[k]<<" ";
                        int a=bin2dec(mintt[k]);
                        out[a]=0;
                    }
                }
               }
            if (sop== -1){
            vector <int> v1;
               vector <string> v3;
               for (int k=0;k<size_;k++){
                    if(out[k]==0){
                       v1.push_back(k);
                    }
               }
               for (int k=0;k<v1.size();k++){
                    string nn = dec2bin(v1[k]);
                    for (int r=nn.length();r<n1;r++){
                        nn = '0'+nn;
                    }
                    string term="(";
                    for (int r=0;r<n1;r++){
                        if (nn[r]=='1'){
                            term.push_back(var[r]);
                            term.push_back('\'');
                             if (r!=n1-1)
                                term.push_back('+');
                        }
                        else{
                            term.push_back(var[r]);
                            if (r!=n1-1)
                                term.push_back('+');
                        }
                    }
                    term.push_back(')');
                    v3.push_back(term);
               }
               cout<<output[i]<< "= ";
               for (int k=0;k<v3.size();k++){
                    cout<<v3[k];
               }
               cout<<endl;
            }
            else{
                vector <int> v1;
               vector <string> v3;
               for (int k=0;k<size_;k++){
                    if(out[k]==1){
                       v1.push_back(k);
                    }
               }
               for (int k=0;k<v1.size();k++){
                    string nn = dec2bin(v1[k]);
                    for (int r=nn.length();r<n1;r++){
                        nn = '0'+nn;
                    }
                    string term="";
                    for (int r=0;r<n1;r++){
                        if (nn[r]=='0'){
                            term.push_back(var[r]);
                            term.push_back('\'');
                        }
                        else{
                            term.push_back(var[r]);
                        }
                    }
                    v3.push_back(term);
               }
               cout<<output[i]<< "= ";
               for (int k=0;k<v3.size();k++){
                    if (k!=v3.size()-1)
                        cout<<v3[k]<<" + ";
                    else
                        cout<<v3[k];
               }
               cout<<endl;
            }
        }
    return 0;
}
