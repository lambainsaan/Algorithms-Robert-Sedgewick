/*
 * In quick find, p and q are connected iff they have the same N.
 *
 * Find - Check if p and q have the same N.
 * Union -  To merge components containing p and q, change all entries
 *          whose N equals N[p] to N[q].
 *
 */


void UF::union_UF(int p, int q){
  int i = 0, pval = *(this->N + p),
   qval = *(this->N + q);
  while (i < this->size) {
    if (*(this->N + i) == pval )
      *(this->N + i) = qval;
    i++;
  };
}
