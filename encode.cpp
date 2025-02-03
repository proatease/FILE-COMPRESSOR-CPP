#include<iostream>
#include"TREE.cpp"
using namespace std;
  void encode(TREE &head)
    {
        char ch;
        string str_to_put = "";
        ifstream inputfile(filename);
        ofstream outputfile("HUFFMANENCODED.txt");
        if(!inputfile || !outputfile)
        {
            cout<<"ERROR  ENCODING FILE"<<endl;
        }
        else{
            while(inputfile.get(ch))
            {
                string str(1,ch);
                    if(head.huffmanCodes.find(str)!= head.huffmanCodes.end())
                    {
                        str_to_put+=head.huffmanCodes[str];
                    }
            }
            outputfile<<str_to_put;
            inputfile.close();
            outputfile.close();
            cout << "\nEncoded file saved as 'HUFFMANENCODED.txt'.\n";
        }
    }
int main()
{
    Linkedlist l1;
    TREE t1;
    readfromfile(l1);

    Linkedlist *head = l1.gethead();
    // l1.dis();

    TREE *root = t1.Huffman_tree_creator(head);

    cout << endl
         << "THE TREE MADE IS " << endl;
    t1.displaytree(root, "");
    encode(t1);
    return 0;
}