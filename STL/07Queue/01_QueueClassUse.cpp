// -------------- Queue -------------
/*
1. Implement stack using queue.
2. Implement priority queue with the given priority range from 1 to N. [Use vector of queues]
3. Given an integer k and a queue of integers. Write a program to reverse the order of the first k elements of the queue.
4. Given a square chessboard of N x N size, the position of the Knight and the position of a target are given. Write a program to find out the minimum steps a Knight will take to reach the target position.
*/


#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Stack
{
    private:
        queue <int> top;
    public:
        bool isEmpty();
        void push(int);
        int peek_top();
        void pop();
};

bool Stack::isEmpty()
{
    return top.empty();
}

void Stack::push(int value)
{
    top.push(value);
}

int Stack::peek_top()
{
    if(top.empty())
        throw -1;
    return top.back();
}

void Stack::pop()
{
    queue <int> temp;
    int len = top.size();
    while(!top.empty())
    {
        if(len == 1)    {
            top.pop();
            break;
        }
        temp.push(top.front());
        top.pop();
        len--;
    }
    if(top.empty())
        top = temp;
}


//Q2
class PriorityQueue
{
private:
    int Capacity;
    vector<queue<int>> pq;
public:
    PriorityQueue(int mxp):Capacity(mxp),pq(mxp){}
    ~PriorityQueue();
    void push(int pno, int data);
    void pop();
    int getHighestPno();
    int get_item();
    bool isEmpty();
};

void PriorityQueue::push(int pno, int data){
    if(pno>0 && pno<Capacity){
        pq[pno-1].push(data);
    }else{
        cout<<"invalid priority \n";
    }
}

void PriorityQueue::pop(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            pq[x].pop();
            break;
        }
}

int PriorityQueue:: getHighestPno(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            return x;
        }
}

int PriorityQueue::get_item(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            return pq[x].front();
        }
}

bool PriorityQueue::isEmpty(){
    for(int x=Capacity-1;x>=0; x--)
        if(!pq[x].empty()){
            return false;
        }
    return true;
}

//Q3
void f3(int k, queue<int>&q){
    queue<int> temp;
    stack<int> s;
    int i=1;
    while (1<=k &&(!q.empty()))
    {
        s.push(q.front());
        q.pop();
        i++;
    }
    while (!q.empty())
    {
        if(i>=1){
            temp.push(s.top());
            s.pop();
            i--;
        }else{
            temp.push(q.front());
            q.pop();
        }
    }
    q=temp;
}

//Q4 
// Possible moves a knight can make
const int dx[] = {2, 1, -1, -2, -2, -1,  1,  2};
const int dy[] = {1, 2,  2,  1, -1, -2, -2, -1};

// Function to check if a position is valid on the chessboard
bool isValid(int n, int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < n);
}

// BFS function to find the minimum steps
int minKnightMoves(int n, int xStart, int yStart, int xTarget, int yTarget) {
  // Create a visited 2D array to keep track of visited cells
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  // Create a queue to store positions for BFS traversal
  queue<pair<int, int>> q;

  // Mark starting position as visited and enqueue it
  visited[xStart][yStart] = true;
  q.push({xStart, yStart});

  int steps = 0; // Keep track of steps taken

  while (!q.empty()) {
    int levelSize = q.size(); // Number of nodes to explore in current level

    for (int i = 0; i < levelSize; i++) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      // Check if target is reached
      if (x == xTarget && y == yTarget) {
        return steps;
      }

      // Try all possible knight moves
      for (int j = 0; j < 8; j++) {
        int newX = x + dx[j];
        int newY = y + dy[j];

        // Check if new position is valid and not visited
        if (isValid(n, newX, newY) && !visited[newX][newY]) {
          visited[newX][newY] = true;
          q.push({newX, newY});
        }
      }
    }

    // Increase steps after exploring all nodes in a level
    steps++;
  }

  // Target not reachable
  return -1;
}




int main() {
  int n, xStart, yStart, xTarget, yTarget;

  // Input chessboard size and starting/target positions
  cout << "Enter chessboard size (N): ";
  cin >> n;

  cout << "Enter starting position (x, y): ";
  cin >> xStart >> yStart;

  cout << "Enter target position (x, y): ";
  cin >> xTarget >> yTarget;

  int minSteps = minKnightMoves(n, xStart, yStart, xTarget, yTarget);

  if (minSteps == -1) {
    cout << "Target cannot be reached from the starting position." << endl;
  } else {
    cout << "Minimum steps required: " << minSteps << endl;
  }

  return 0;
}