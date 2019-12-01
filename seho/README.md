# 트리 (Tree)
 트리는 "Connected Acycled Graph" 이다.
 
 ## 그래프 (Graph)
  ```
   A graph G is pair(V, E) where V is a finite, nonempty set whose elements are called vertices,
   and E is a set of subsets of V of order two. Vertices are called nodes. Elements of E are called edges.
  ```
 
 ### Acyclic
    Acyclic graph는 cycle이 없는 그래프를 말한다.
    Cycle은 시작점과 끝점이 같은 길이 2이상의 path를 갖는 경우 를 말한다.

 ### Connected
    모든 정점(vertex)간의 경로(path)가 존재하는 경우에 그 그래프는 Connected Graph이다.


 즉, 트리는 모든 정점간 경로가 존재하고, 시작점과 끝점이 같은 2 이상의 경로가 없는 정점(Vertex)과 간선(Edge)의 쌍의 집합을 말한다.
 참고로, Forest는 acyclic graph이다. tree가 여러개로 나누어져 있는 것을 말한다.
 

# 트리의 구현과 순회
- 기본적인 노드(Vertex) 구조체
```C++
 struct Node {
  Node* parent;
  Node* leftchild;
  Node* rightchild;
  int value   
}

// postoder traversal
int PostTraverse(Node* curr)
{
	PostTraverse(curr->left_child);
	PostTraverse(curr->right_child);
	std::cout << curr->value;

	return 0;
}


```


# 이진 검색 트리
 Right subtree 에는 해당 노드보다 큰값, Left subtree에는 해당 노드보다 작은 값을 저장하는 트리.
자료의 탐색이 빠른 이진 탐색과 자료의 추가/삭제가 용이한 리스트의 장점을 모두 가진 자료 구조이다.

``` C++
// 이지 검색 트리에서의 이진 탐색 구현
 Node* findNode(Node* currentNode,int val){
    if (currentNode is None)
        return -1;
    else if (val == currentNode->value)
        return currentNode;
    else if (val < currentNode->value)
        return findNode(currentNode->leftChild, val);
    else:
        return findNode(currentNode->rightChild, val;
 }
```


