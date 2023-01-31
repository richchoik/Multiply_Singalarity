///VNCSDang
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define task "mul_str"
using namespace std;

string Num1, Num2;

string add(string num1, string num2)
{
    string res="";
    while(num1.size()<num2.size()) num1="0"+num1;
    while(num2.size()<num1.size()) num2="0"+num2;
    int carry=0;
    for(int i=num1.size()-1;i>=0;i--)
    {
        int cur_res=num1[i]-48+num2[i]-48+carry; ///cong cac so theo cot
        carry=cur_res/10;                        ///cap nhat gia tri nho
        cur_res=cur_res%10;
        res=(char)(cur_res+48)+res;              ///cap nhat tong
    }
    if(carry>0) res="1"+res;
    return res;
}

string mul(int num1, string num2)   ///nhan so co 1 cso voi so co nhieu cso
{
    string res="";
    int carry=0;
    int n=num2.size();
    for(int i=n-1;i>=0;i--)
    {
        long long cur_res=(num1)*(num2[i]-48)+carry;
        carry=cur_res/10;
        res+=(char)(cur_res%10+48);
    }
    if(carry>0)
    {
        while(carry!=0)
        {
            res+=(char)(carry%10+48);
            carry/=10;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

string multiply(string num1, string num2)
{
    string res="";
    int n=num1.length();
    string cur[n];
    for(int i=n-1;i>=0;i--)
    {
        cur[i]=mul(num1[i]-48,num2);
        cur[i].insert(cur[i].length(),n-i-1,'0');
        res=add(res,cur[i]);
    }
    if(res[0]=='0') res="0";
    return res;
}

int main()
{
    cin>>Num1>>Num2;
    string Res=multiply(Num1,Num2);
    cout<<Res;
    return 0;
}
