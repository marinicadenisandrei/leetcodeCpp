/* Leetcode - 93. Restore IP Addresses (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> restoreIpAddresses(string sVar);
void printVector(vector <string> vectorVar);
int countSubstringInString(string sub, string stringVar);
void replaceAll(string &str, const string &oldSubstring, const string& newSubstr);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 93. Restore IP Addresses (C++ language) - Medium" << endl;

    vector<string> s {"25525511135","0000","101023"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector <string> output = restoreIpAddresses(s[test]);
        printVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int countSubstringInString(string sub, string stringVar)
{
    int count {0};
    size_t pos = 0;

    while ((pos = stringVar.find(sub, pos)) != string::npos)
    {
        count++;
        pos += sub.length();
    }


    return count;
}

void printVector(vector <string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");  
    }
}

void replaceAll(string &str, const string &oldSubstring, const string& newSubstr)
{
    size_t pos = 0;

    while ((pos = str.find(oldSubstring, pos)) != string::npos)
    {
        str.replace(pos, oldSubstring.length(), newSubstr);
        pos += newSubstr.length();
    }
}

vector <string> restoreIpAddresses(string sVar)
{
    vector <string> ips = {};
    string ipformation {""};
    string copyIpFormat {""};
    string replacement = "";

    int blockers = 0;

    blockers = countSubstringInString("255", sVar); 

    if (blockers > 0)
    {
        for (int i = 0; i < blockers; i++)
        {
            replacement += "255";
            replacement += ".";
        }
        
        replaceAll(sVar, "255", "");
    }

    bool flag {true};

    string lastElements = sVar.substr(sVar.length() - 4 + blockers);
    string suffix = sVar.substr(0, sVar.length() - 4 + blockers);

    for (auto i : lastElements)
    {
        ipformation += i;
        ipformation += ".";
    }
    
    ipformation = suffix + ipformation;
    ipformation.erase(ipformation.size() - 1);

    copyIpFormat = ipformation;
    
    bool addIp = true;
    ipformation += ".";
    string tempValue = "";

    for (int i = 0; i < ipformation.size(); i++)
    {   
        if (ipformation[i] != '.')
        {
            tempValue += ipformation[i];
        }
        else
        {
            if (tempValue.size() > 1 && tempValue[0] == '0')
            {
                addIp = false;
                break;
            }
            else
            {
                int num = stoi(tempValue);

                if (num > 255)
                {
                    addIp = false;
                    break;
                }
            }
        
            tempValue = "";
        }
    }

    ipformation.erase(ipformation.size() - 1);

    if (addIp)
    {
        ips.push_back(ipformation);
    }

    flag = true;
    
    while (flag)
    {
        flag = false;

        for (int i = ipformation.size() - 1; i >= 2 ; i--)
        {
            if (ipformation[i] == '.' && ipformation[i - 2] != '.')
            {
                char temp[2];
                temp[0] = ipformation[i];
                ipformation[i] = ipformation[i - 1];
                ipformation[i - 1] = temp[0];
                
                string tmp = "";
                bool flagIp = true;

                ipformation += ".";

                for (int j = 0; j < ipformation.size(); j++)
                {
                    if (ipformation[j] != '.')
                    {
                        tmp += ipformation[j];
                    }
                    else
                    {
                        if (tmp.size() > 1 && tmp[0] == '0')
                        {
                            flagIp = false;
                            break;
                        }
                        else
                        {
                            int num = stoi(tmp);

                            if (num > 255)
                            {
                                flagIp = false;
                                break;
                            }
                        }
                    
                        tmp = "";
                    }
                }

                ipformation.erase(ipformation.size() - 1);

                if (flagIp)
                {
                    if (blockers > 0)
                    {
                        ips.push_back(replacement + ipformation);
                    }
                    else
                    {
                        ips.push_back(ipformation);
                    }
                }
                
                flag = true;

                break;
            }
        }
    }

    flag = true;
    ipformation = copyIpFormat;

    while (flag)
    {
        flag = false;

        for (int i = 2; i < ipformation.size(); i++)
        {
            if (ipformation[i] == '.' && ipformation[i - 2] != '.')
            {
                char temp[2];
                temp[0] = ipformation[i];
                ipformation[i] = ipformation[i - 1];
                ipformation[i - 1] = temp[0];
                
                string tmp = "";
                bool flagIp = true;

                ipformation += ".";
                

                for (int j = 0; j < ipformation.size(); j++)
                {
                    if (ipformation[j] != '.')
                    {
                        tmp += ipformation[j];
                    }
                    else
                    {
                        if (tmp.size() > 1 && tmp[0] == '0')
                        {
                            
                            flagIp = false;
                            break;
                        }
                        else
                        {
                            int num = stoi(tmp);

                            if (num > 255)
                            {
                                flagIp = false;
                                break;
                            }                            
                        }
                    
                        tmp = "";
                    }
                }

                ipformation.erase(ipformation.size() - 1);

                if (flagIp)
                {
                    if (blockers > 0)
                    {
                        ips.push_back(replacement + ipformation);
                    }
                    else
                    {
                        ips.push_back(ipformation);
                    }
                }
                
                flag = true;

                break;
            }
        }
    }

    sort(ips.begin(), ips.end());
    ips.erase(unique(ips.begin(), ips.end()), ips.end());

    return ips;
}

void reset () {
  cout << "\033[1;0m";
}

void green () {
  cout << "\033[1;32m";
}

void yellow () {
  cout << "\033[1;33m";
}

void red () {
  cout << "\033[1;31m";
}