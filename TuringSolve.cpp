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

int TuringPParity(vector<int>& code){
    if(code[2] % 2 == 0){
		return 0;
	}else{
		return 1;
	}
}

int TuringBCmp1(vector<int>& code){
    if(code[0] == 1){
		return 0;
	}else{
		return 1;
	}
}

int TuringSmall(vector<int>& code){
    if(code[0] < code[1] && code[0] < code[2]){
        return 0;
    } else if(code[1] < code[0] && code[1] < code[2]){
        return 1;
    } else if(code[2] < code[1] && code[2] < code[0]){
        return 2;
    } else{
        return -1;
    }
}

int TuringYCmpP(vector<int>& code){
    if(code[1] < code[2]){
        return 0;
    }else if(code[1] == code[2]){
        return 1;
    }else{
        return 2;
    }
}

int Turing4s(vector<int>& code){
    int num = 0;
	    for(int i : code){
	        if(i == 4){
	            num++;
	        }
	    }
	    return num;
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
    TuringPParity,  //10 紫色的奇偶性
    TuringBCmp1, //11 蓝色比1大小
    TuringSmall, //12 哪个颜色的数字严格最小
    TuringYCmpP, //13 黄色和紫色比较
    Turing4s, //14 有几个4
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
                    if(functions[a](code) == -1 || functions[b](code) == -1 || functions[c](code) == -1 || functions[d](code) == -1){
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
    int a = 11;
    int b = 12;
    int c = 13;
    int d = 14;
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
