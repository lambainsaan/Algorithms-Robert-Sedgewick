/*
 * In quick find, p and q are connected iff they have the same N.
 *
 * Connected - Check if p and q have the same N.
 * Union -  To merge components containing p and q, change all entries
 *          whose N equals N[p] to N[q].
 *
 */
UF::UF(int size){
  /*
   * Initialization of the union data structure.
   * Takes time propotional to O(N).
   */
  int i = 0;
  this->N = new int[size];
  this->size = size;
  while(i < size ) this->N [i] = i++;
};

void UF::union_UF(int p, int q){
  /*
   * Does a union of the two components containing p and q.
   * It takes time propotional to O(N).
   */
  int i = 0, pval = this->N [p],
   qval = this->N [q];
  while (i < this->size) {
    if (this->N [i] == qval ) {
      this->N [i] = pval;
    }
    i++;
  };
};


bool UF::connected(int p, int q){
  /*
   * Returns True or False depending on the fact if p is connected to q.
   * Takes time propotional to O(1)
   */
  return this->N[p] == this->N[q];
};
