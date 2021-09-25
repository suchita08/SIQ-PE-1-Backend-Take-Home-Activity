#include <bits/stdc++.h>
using namespace std;
class parking_lot
{
    public:
    int n;
    bool *slot;
    
    struct person 
    {
        int slotNo;
        string registeration_number;
        int age;
    };
    struct person  *p;
    void Create_parking_lot(int no_of_slots)
    {
        n=no_of_slots;
        slot=(bool*)calloc(no_of_slots,sizeof(bool));
        p=(struct person*)calloc(no_of_slots,sizeof(struct person));
    }
   
    int getSlot(string reg,int a)
    {
        for(int i=0;i<n;i++)
        {
            if(slot[i]==0)
            {
                p[i].slotNo=i+1;
                slot[i]=1;
                p[i].age=a;
                p[i].registeration_number=reg;
                return i+1;
            }
        }
    }


    vector<int> total_no_of_slot(int a)
    {
        vector<int> slots;
        for(int i=0;i<n;i++)
        {
            if(p[i].age==a){
                
                slots.push_back(p[i].slotNo);

            }    
            }
        return slots;
    }


    int getSlotNumber(string reg)
    {
        
        for(int i=0;i<n;i++)
        {
            if(p[i].registeration_number==reg)
                return p[i].slotNo;
        }
        return -1;
    }
    
    string leave(int slot_no)
    {
        vector<string>a;
        if(slot[slot_no]==0) 
            return "Slot Already Vacant";
       else
       {
           string res="";
           res="Slot number "+to_string(slot_no)+ " vacated, the car with vehicle registration number "+p[slot_no].registeration_number+" left the space, the driver of the car was of age "+to_string(p[slot_no].age);
            slot[slot_no]=0;
            p[slot_no].age=0;
            p[slot_no].registeration_number="";
            p[slot_no].slotNo=0;
            return res;
       }
    }
    
    vector<string> getPersonWithAge(int a)
    {
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            if(p[i].age==a)
            {
                ans.push_back(p[i].registeration_number);
            }
        }
        return ans;
    }

};
int main()
{
        // cin>>n;
        // parking_lot a(n);
        fstream input;
        ofstream output;
        output.open("output.txt");
        input.open("input.txt",ios::in);
        if(!input)
        {
            cout<<"no such file";
        }
        else
        {
            string s;
            parking_lot pl; 
            while(getline(input,s))
            {
                vector<string> tokens;
                stringstream check1(s);
                string intermediate;
                while(getline(check1,intermediate,' '))
                {
                    tokens.push_back(intermediate);
                }
                if(tokens[0]=="Park")
                {
                    int slotNo=pl.getSlot(tokens[1],stoi(tokens[3]));
                    output<<"Car with vehicle registration number "<<tokens[1]<<" has been parked at slot number "<<slotNo<<"\n";

                }
                else if(tokens[0]=="Create_parking_lot")
                {
                    pl.Create_parking_lot(stoi(tokens[1]));
                    output<<"Created parking of "<<tokens[1]<< " slots"<<"\n";
                }
                else if(tokens[0]=="Slot_numbers_for_driver_of_age")
                {
                    vector<int>ttl;
                    ttl=pl.total_no_of_slot(stoi(tokens[1]));
                    for(int i=0;i<ttl.size();i++)
                        output<<ttl[i]<<",";
                    output<<"\n";
                }
                else if(tokens[0]=="Slot_number_for_car_with_number")
                {
                    int slotno=pl.getSlotNumber(tokens[1]);
                    output<<slotno<<"\n";
                }
                else if(tokens[0]=="Vehicle_registration_number_for_driver_of_age")
                {
                    vector<string> s;
                    s=pl.getPersonWithAge(stoi(tokens[1]));
                    for(int i=0;i<s.size();i++)
                        output<<s[i]<<",";
                   
                    output<<"\n";
                }
                else 
                {
                    string res=pl.leave(stoi(tokens[1]));
                    output<<res<<"\n";
                    
                }
            }
        }
        input.close();
        return 0;
        
        
   
    
        
}