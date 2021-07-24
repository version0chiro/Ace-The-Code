class Solution {
public:

    string reformatDate(string date) {
        unordered_map<string, string> m =
        {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr","04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug","08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec","12"}
        };
        string day="",month="",year="";
        
        string temp="";
        
        int i=0;
        
        for(;i<date.size();i++){
            if(date[i]=='t' || date[i]=='n' || date[i]=='r' || date[i]=='s') break;
            day+=date[i];
        }
        
        while(date[i]!=' '){
         
            i++;
        }
        while(date[i]==' '){
            i++;
        }
        
        while(date[i]!=' '){
            temp+=date[i];
            i++;
        }
        cout<<temp<<"\n";
        month=m[temp];
        cout<<month;
        
        
        cout<<day;
        
        
        year=date.substr(date.length()-4,4);
        cout<<year;
        if(day.size()==1){
            day="0"+day;
        }
        return year+"-"+month+"-"+day;
        
    }
};