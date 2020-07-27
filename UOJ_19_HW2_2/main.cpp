#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

bool append_newline=true;
bool backslash_inter;

bool order(char* str){
    int len=(int)strlen(str);
    if(str[0]!='-') return false;
    else for(int i=1;i<len;i++)
        if(str[i]!='n'&&str[i]!='E'&&str[i]!='e') return false;
    for(int i=1;i<len;i++){
        if(str[i]=='n') append_newline=false;
        else if(str[i]=='e') backslash_inter=true;
    } 
    return true;
}

void print_line(int s,int f,char* str){
    int flag=s;
    while(flag<=f){
        if(str[flag]!='\\') cout<<str[flag];
        else if(backslash_inter){
            switch(str[flag+1]){
                case 'a':{
                    cout<<'\a';
                    break;
                }
                case 'b':{
                    cout<<'\b';
                    break;
                }
                case 'c': exit(0);
                case 'e':{
                    cout<<'\x1B';
                    break;
                }
                case 'E':{
                    cout<<'\x1B';
                    break;
                }
                case 'f':{
                    cout<<'\f';
                    break;
                }
                case 'n':{
                    cout<<'\n';
                    break;
                }
                case 'r':{
                    cout<<'\r';
                    break;
                }
                case 't':{
                    cout<<'\t';
                    break;
                }
                case 'v':{
                    cout<<'\v';
                    break;
                }
                case '\\':{
                    cout<<'\\';
                    break;
                }
                default: cout<<"\\"<<str[flag+1];
            }
            flag++;
        }
        else cout<<str[flag];
        flag++;
    }
    return;
}

void print_block(int num,char** str,int loc_s){
    for(int i=loc_s;i<num;i++){
        if(str[i][0]=='"') print_line(1,strlen(str[i])-2,str[i]);
        else print_line(0,strlen(str[i])-1,str[i]);
        if(i!=num-1) cout<<' ';
    }
    if(append_newline) cout<<endl;
    return;
}

int main(int argc,char** argv){
    if(order(argv[1])) print_block(argc,argv,2);
    else print_block(argc,argv,1);
    return 0;
}