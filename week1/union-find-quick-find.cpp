/*
 * In quick find, p and q are connected iff they have the same id.
 *
 * Find - Check if p and q have the same id.
 * Union -  To merge components containing p and q, change all entries
 *          whose id equals id[p] to id[q].
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

bool UF::connected(int p, int q){
  return *(this->N + p) == *(this->N + q);
}
