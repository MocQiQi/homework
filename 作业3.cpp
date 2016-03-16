#include <iostream>  
#include <string>//字符串  
using namespace std;  
 
 struct Word  
 {   string Str;  
     int Count;  

     void exchange(Word &word)  
    {  
         string tStr = word.Str;  
         int tCount = word.Count;  
         word.Str = Str;  
         word.Count = Count;  
         Str = tStr;  
         Count = tCount;  
     }  
 };  
 
 void CalcCount(Word * words, string &newWord, int size)  
 {  
     int i = 0;  
     for(; i < size; i++)  
     {  
        if(words[i].Str == newWord)  
         {  
             words[i].Count++;  
             return;  
         }  
         else if(words[i].Str == "")  
             break;  
     }  
    words[i].Str = newWord;  
     words[i].Count = 1;  
 }  
  
 void SortWordDown(Word * words, int size)  
 {  
     for(int i = 0; i < size; i++)  
     {  
         for(int j = 0; j < size-1; j++)  
         {  
             if(words[j].Count <  words[j+1].Count)  
             {  
                 words[j].exchange(words[j+1]);  } }  } }  
   
 int main()  
 {  
     Word * words;  
     string content;  
     cout << "";  
     getline(cin, content);  
   
     //计算单词总数  
     int wCount = 1;  
     for(unsigned int i = 0; i < content.length(); i++)  
     {  
         if(content[i] == ' ')  
             wCount++;  
     }  
     words = new Word[wCount];  
   
     string::size_type offset = content.find(' ');//单词都是以空格隔开  
     while(offset != string::npos)  
     {  
         string wStr = content.substr(0, offset);  
         content.erase(0, offset+1);  
         CalcCount(words, wStr, wCount);  
         offset = content.find(' ');  
     }  
     CalcCount(words, content, wCount);//计算最后一个单词  
   
     SortWordDown(words, wCount);  
     int printCount = wCount < 5 ? wCount : 5;  
     cout << "单词分别出现的频率:" << endl;  
     for(i = 0; i < printCount; i++)  
     {  
         cout << words[i].Str << "出现的频率:" << words[i].Count << "次" << endl;  
     }  
   
     delete [] words;//释放内存  
     return 0;  
 }  