#include<iostream>
#include<vector>
#include <functional>
using namespace std;

int TuringBCmp3(vector<int>& code){
    int key = code[0];
    if(key < 3){
        return 0;
    } else if(key == 3){
        return 1;
    }else{
        return 2;
    }
}

int TuringYCmp3(vector<int>& code){
    int key = code[1];
    if(key < 3){
        return 0;
    } else if(key == 3){
        return 1;
    }else{
        return 2;
    }
}

int TuringPCmp3(vector<int>& code){
    int key = code[2];
    if(key < 3){
        return 0;
    } else if(key == 3){
        return 1;
    }else{
        return 2;
    }
}

int Turing1s(vector<int>& code){
    int num = 0;
    for(int i : code){
        if(i == 1){
            num++;
        }
    }
    return num;
}

int Turing3s(vector<int>& code){
    int num = 0;
    for(int i : code){
        if(i == 3){
            num++;
        }
    }
    return num;
}

int TuringBCmpY(vector<int>& code){
    if(code[0] < code[1]){
        return 0;
    }else if(code[0] == code[1]){
        return 1;
    }else{
        return 2;
    }
}

int TuringBCmpP(vector<int>& code){
    if(code[0] < code[2]){
        return 0;
    }else if(code[0] == code[2]){
        return 1;
    }else{
        return 2;
    }
}

int TuringEvens(vector<int>& code){
    int num = 0;
    for(int i : code){
        if(i % 2 == 0){
            num++;
        }
    }
    return num;
}

int TuringBIG(vector<int>& code){
    int key = code[0];
    if(code[0] > code[1] && code[0] > code[2]){
        return 0;
    } else if(code[1] > code[0] && code[1] > code[2]){
        return 1;
    } else if(code[2] > code[1] && code[2] > code[0]){
        return 2;
    } else{
        return -1;
    }
}

int TuringOddMore(vector<int>& code){
    int odd = 0;
    int even = 0;
    for(int i : code){
        if(i % 2 == 0){
            even++;
        } else{
            odd++;
        }
    }
    if(even > odd){
        return 0;
    } else if(odd > even){
        return 1;
    } else {
        return -1;
    }
}

int TuringPOdd(vector<int>& code){
    if(code[2] % 2 == 0){
        return 0;
    }
    return 1;
}

void printCode(vector<int>& code){
    cout<<"("<<code[0]<<" "<<code[1]<<" "<<code[2]<<")"<<endl;
}

std::function<int(vector<int>&)> functions[] = {
    TuringYCmp3, //0 黄色比3大小
    Turing1s,   //1 有几个1
    TuringBCmpP,    //2 蓝色和紫色比大小
    TuringEvens,    //3 有几个偶数
    TuringBCmp3,    //4 蓝色比3大小
    Turing3s,    //5 有几个3
    TuringBIG,    //6 哪个颜色的数字严格最大
    TuringOddMore,    //7 偶数多还是奇数多
    TuringPCmp3,    //8 紫色和3比大小
    TuringBCmpY,    //9 蓝色和黄色比大小
    TuringPOdd,     //10 紫色是偶数吗
    // ... 添加其他函数
};

bool test3code(vector<int>& code, int a, int b, int c){
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            for(int k = 1; k <= 5; k++){
                vector<int> code2 = {i, j, k};
                if(code != code2){
                    if(functions[a](code) == functions[a](code2) && functions[b](code) == functions[b](code2)
                    && functions[c](code) == functions[c](code2)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool test4Code(vector<int>& code, int a, int b, int c, int d){
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            for(int k = 1; k <= 5; k++){
                vector<int> code2 = {i, j, k};
                if(code != code2){
                    if(functions[a](code) == functions[a](code2) && functions[b](code) == functions[b](code2)
                    && functions[c](code) == functions[c](code2) && functions[d](code) == functions[d](code2)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> ans;
    
    //需要验证的图灵机的编号
    int a = 4;
    int b = 5;
    int c = 6;
    int d = 10;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            for(int k = 1; k <= 5; k++){
                vector<int> code = {i, j, k};
                if(test4Code(code, a, b, c, d) && !test3code(code, a, b, c) && !test3code(code, a, b, d) 
                && !test3code(code, a, c, d) && !test3code(code, b, c, d)){
                    ans.push_back(code);
                }
            }
        }
    }

    for(auto i : ans){
        printCode(i);
    }
    return 0;
}