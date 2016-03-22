#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
struct Word{      //定义结构体
    int Count;//计数器
     Word() : Str(""), Count(0) {}  
    string Str; //字符串
    char *p;
};
void exchange(Word &word)  //排序    
{  
    string tStr = word.Str;  
    int tCount = word.Count;  
    word.Str = Str; 
    word.count =count ; 
    Str = tStr;  
    Count = tCount;  
}  

Words test[100];

void lwr(char x[])     //大写转小写
{   int k = 0;
    while (x[k] != '\0')
    {
        if (x[k] >= 'A'&&x[k] <= 'Z')
            x[k] = x[k] + 32;
        k++;
    }
}

int identify(char a[])    //判断是否符合定义
{   int m=(strlen(a)>=4)?1:0;
    int n=(a[0]>='a'&&a[0]<='z')?1:0;
    if(!m||!n)
        return 0;
    else
        while(a)
        {   for(int i=1;;i++)
           {  
               if(!(a[i]>='a'&&a[i]<='z')||!(a[i]>='0'&&a[i]<='9'))
                        return 0;
               else
                        return 1;
           }
        }
}

void SortWordDown(Word * words, int size)  //以单词出现频率降序排列单词，words 表示单词数组，size 表示单词数量
{  
    for(int i=0;i<size;i++)  
    {
        for(int j=0;j <size-1;j++)  
        { 
            if(words[j].Count<words[j+1].Count)  
            {  
                words[j].exchange(words[j+1]);  
            }  
        }  
    }  
}  

int counting(char b[],int num)    //对出现次数计数
{   for(int j=0;j<num;j++)
    {if(!strcmp(b,test[j].p))
             test[j].count++;
        else
            return 0;
    }
}
int main()
{   char c[200];
    ifstream fin("D:/A_Tale_of_Two_Cities.txt");   //从文档中获取字符串
    for(int f=0;;f++)
        fin>>c[f];
    fin.close();
    cin.get();
    lwr(c);
    const char *delim = ",”“.''!?";      //分割字符串
    char *q;
    int n=0;
    q = strtok(c, delim);
    SortWordDown(words, wCount);  
    while (q)
    {
        if (identify(q))
        { strcpy(test[n].p,q);
            n++;}
        ofstream Result1; 
        Result1.open("Result1.txt"); //将内容输入到"Result1.txt"这个文件里，若无此文件，则自动创建这个文件
        Result1<< test[n].p << ":" << test[n].count << '\n';//想要的输出内容
        q=strtok(NULL,delim);
    }
    return 0;
}