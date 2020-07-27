#include <iostream>
#include <string>
#include <cstring>

std::string upper_kanji[10]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
std::string lower_kanji[10]={"零","一","二","三","四","五","六","七","八","九"};
std::string upper_eng[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
std::string lower_eng[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

bool notin(char ch){
    if(ch=='C') return false;
    if(ch=='c') return false;
    if(ch=='e') return false;
    if(ch=='E') return false;
    return true;
}

bool not_num(char* str){
    int len=(int)strlen(str);
    for(int i=0;i<len;i++)
        if(str[i]<'0'||str[i]>'9') return true;
    return false;
}

bool legal(int num,char** str){
    if(num!=4) return false;
    if(strcmp(str[1],"-L")!=0) return false;
    if(notin(str[2][0])) return false;
    if(not_num(str[3])) return false;
    return true;
}

int main(int argv,char** argc){
    if(argv==1){
        std::cout<<"usage: convert -L command digit-string"<<std::endl;
        std::cout<<"command = C|c|E|e"<<std::endl;
        std::cout<<"example: convert -L C 2018"<<std::endl;
    }
    else if(legal(argv,argc)){
        int len=(int)strlen(argc[3]);
        switch(argc[2][0]){
            case 'C':{
                for(int i=0;i<=len-1;i++) std::cout<<upper_kanji[(int)argc[3][i]-48];
                std::cout<<std::endl;
                break;
            }
            case 'c':{
                for(int i=0;i<=len-1;i++) std::cout<<lower_kanji[(int)argc[3][i]-48];
                std::cout<<std::endl;
                break;
            }
            case 'E':{
                for(int i=0;i<=len-1;i++) std::cout<<upper_eng[(int)argc[3][i]-48]<<' ';
                std::cout<<std::endl;
                break;
            }
            case 'e':{
                for(int i=0;i<=len-1;i++) std::cout<<lower_eng[(int)argc[3][i]-48]<<' ';
                std::cout<<std::endl;
                break;
            }
            default: break;
        }
    }
    else{
        std::cout<<"error input!"<<std::endl;
        std::cout<<"usage: convert -L command digit-string"<<std::endl;
        std::cout<<"command = C|c|E|e"<<std::endl;
        std::cout<<"example: convert -L C 2018"<<std::endl;
    }
    return 0;
}