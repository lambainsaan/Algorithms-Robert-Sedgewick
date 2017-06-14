/*
 * Root of i is N[N[N[...N[i]...]]]
 *
 * Find - Check if p and q have the same root.
 * Union -  To merge components containing p and q,
 *          set the id of p's root to the id of q's root.
 *
 */

 UF::UF(int size){
   /*
     Initialization of the union data structure.
    */
   int i = 0;
   this->N = new int[size];
   this->size = size;
   while(i < size ) *(this->N + i) = i++;
 };

void UF::union_UF(int p, int q){
  this->N[this->root(p)] = this->root(q);
};

bool UF::connected(int p, int q){
  return this->root(p) == this->root(q);
}
