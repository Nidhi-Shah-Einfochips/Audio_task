#include<iostream>
#include<string>
#include<memory>
#include<map>
#include<fstream>
using namespace std;
class AudioStreamIF
{
 public:
 	int i;
    enum  streamfile
    {
        OGG,
        WAV,
        FLAC,
        INVALID
        
    };
    virtual bool isValidStream( string& streamHeader ) = 0;
};class WAV : public AudioStreamIF
{
    public:
   const string magicWord = "RIFF";
  virtual bool isValidStream(std::string& streamHeader)
  {
      if (magicWord == streamHeader)        return true;  
    else
        return false;    }
};class OGG :public AudioStreamIF
{   
    public:
   const string magicWord = "OggS";
  virtual bool isValidStream(std::string& streamHeader)
  {
      if (magicWord == streamHeader)
        return true; 
    else
        return false;     
  }
};class FLAC : public AudioStreamIF
{
    public:
 const string magicWord = "FlaC";
  virtual bool isValidStream(std::string& streamHeader)
  {
      if (magicWord == streamHeader)
        return true;  
    else
        return false;     }};class AudioStreamManger 
{   
    public:
    static char  DectectStream( std::string& streamHeader  )
    {
    map<string,AudioStreamIF*> m;
     m["OGG"]=  new OGG();
     m["WAV"] = new  WAV();
     m["FLAC"] =new  FLAC();     for(auto& item :m)
     {
         if(item.second -> isValidStream( streamHeader))
         {
             cout << item.first << endl;
         }
     }
     cout<<streamHeader<<endl;
      }};
int main()
{
    char a[5] ;
    string s = " ";
    char filename[50];
    cout<<"enter the filename \n";
    cin>>filename;
    ifstream infile(filename, fstream::in);
    for(int i= 0 ; i<4 ;i++)
    {
        infile>>a[i];
        s = s + a[i];
    }
    AudioStreamManger m1;
    m1.DectectStream(s);
}
