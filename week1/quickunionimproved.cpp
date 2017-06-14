/*
 * Root of i is N[N[N[...N[i]...]]]
 *
 * Find - Check if p and q have the same root.
 * Union -  To merge components containing p and q,
 *          set the id of p's root to the id of q's root.
 *
 */

UF::UF(int size){
    int i = 0;
    this->N = new int[size];
    this->sz = new int[size];
    this->size = size;
    while(i < size && (this->sz[i] = 1)) this->N[i] = i++;
  };
void UF::union_UF(int p, int q){
  int p_root = this->root(p), q_root = this->root(q);
  if (this->sz[p_root] < this->sz[q_root]){
    this->N[p_root] = q_root;
    this->sz[q] += this->sz[p];
  }
  else{
    this->N[q_root] = p_root;
    this->sz[p] += this->sz[q];
  }

}

bool UF::connected(int p, int q){
  return this->root(p) == this->root(q);
}
