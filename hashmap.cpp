std::hash<std::string> str_hash;
std::hash<int> int_hash;

class Node
{
    public: 
    Node(){this->next=nullptr;}
    Node(int k,int v):key(k),value(v),next(nullptr){}
    int key;
    int value;
    Node *next;
};

class MyHashMap:public Node
{
    public:
    vector<Node*> nodes;
    MyHashMap()
    {
        nodes.resize(10000);
    }
    int index(int key)
    {

        return (int_hash(key)%nodes.size());
       
    }
    void put(int key,int value)
    {
        int idx=index(key);
        if(nodes[idx]==nullptr)
        {
           nodes[idx]=new Node(key,value);
        }
        else if(nodes[idx]->key==key)
        {
            nodes[idx]->value=value;
        }
        else
        {
          Node *head=nodes[idx];
          Node *previous;
          while(head!=nullptr && head->key!=key)
          {
              previous=head;
              head=head->next;
          }
          if(head==nullptr)
          {
              previous->next=new Node(key,value);
          }
          else if(head->key==key)
          {
              head->value=value;
          }
        }
    }

    int get(int key) 
    {
        int idx = index(key);
        if(nodes[idx]==nullptr)
        {
            return -1;
        }
        else if(nodes[idx]->key==key)
        {
            return nodes[idx]->value;
        }
        else
        {
          Node *head=nodes[idx];
          Node *previous;
          while(head!=nullptr && head->key!=key)
          {
              previous=head;
              head=head->next;
          }
          if(head==nullptr)
          {
              return -1;
          }
           else if(head->key==key)
          {
              return head->value;
          }  
        }
        return -1;
    }
    void remove(int key)
    {
        int idx = index(key);
        if(nodes[idx]==nullptr)
        {
            return;
        }
        else if(nodes[idx]->key==key)
        {
            nodes[idx]=nullptr;
            return;
        }
        else
        {
          Node *head=nodes[idx];
          Node *previous;
          while(head!=nullptr && head->key!=key)
          {
              previous=head;
              head=head->next;
          }
          if(head==nullptr)
          {
              return;
          }
           else if(head->key==key)
          {
              Node *temp=head;
              previous->next=head->next;
              delete temp;
          }  
        }
    }
    
};