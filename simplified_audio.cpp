#include<iostream>
#include<string>
#include<memory>
#include<map>
#include<fstream>
using namespace std;
class AudioStreamIF
{
 public:
    enum  streamfile
    {
        OGG,
        WAV,
        FLAC,
        INVALID
    };
    virtual bool isValidStream( string& streamHeader ) = 0;
};

class WAV : public AudioStreamIF
{
    public:
    
  const string magicWord = "RIFF";


  virtual bool isValidStream(std::string& streamHeader)
  { 
      char word[5] =" ";
        for(int i= 0 ; i<5 ;i++)
    {
            word[i]=streamHeader[i];

    }
    cout<<" 4 bytes "<<word<<endl;
      if (magicWord == word)

      //streamHeader = " ";
      //if (magicWord == streamHeader)
       // if(streamHeader.length()<4)
            {
                return true;
            }
  
    else
        return false;  

  }
    
};

class OGG :public AudioStreamIF
{   
    public:
   const string magicWord = "OggS";


  virtual bool isValidStream(std::string& streamHeader)
  {
      char word[5] =" ";
        for(int i= 0 ; i<5 ;i++)
    {
            word[i]=streamHeader[i];

    }
    cout<<" 4 bytes "<<word<<endl;
      if (magicWord == word)
      

     // if (magicWord == streamHeader)
        return true; 
    else
        return false;     
  }
};

class FLAC : public AudioStreamIF
{
    public:
 const string magicWord = "FlaC";


  virtual bool isValidStream(std::string& streamHeader)
  {
      char word[5] =" ";
        for(int i= 0 ; i<5 ;i++)
    {
            word[i]=streamHeader[i];

    }
    cout<<" 4 bytes "<<word<<endl;
      if (magicWord == word)
        return true;  
    else
        return false;   

  }

};

class AudioStreamManger 
{   
    public:
    
    static char  DectectStream( std::string& streamHeader  )
    {
         shared_ptr<AudioStreamIF>sp(new OGG);
         cout<<sp->isValidStream(streamHeader)<<endl;

        // // };
        

    map<string,AudioStreamIF*> m;
     m["OGG"]=  new OGG();
     m["WAV"] = new  WAV();
     m["FLAC"] =new  FLAC();

     for(auto& item :m)
     {
         if(item.second -> isValidStream( streamHeader))
         {
             cout << item.first << endl;
         }
     }
     
     cout<<streamHeader<<endl;
      }

};

int main()
{
    char a[5] ;
    string s = " ";
    char filename[50];
    cout<<"enter the filename \n";
    cin>>filename;
    ifstream infile(filename, fstream::in); //should we need to write this chunk of the code in all the class or here
    for(int i= 0 ; i<16 ;i++)
    {
        infile>>a[i];
        s = s + a[i];
    }

    AudioStreamManger m1;
    m1.DectectStream(s);
}