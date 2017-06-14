/*
 * Root of i is N[N[N[...N[i]...]]]
 *
 * Find - Check if p and q have the same root.
 * Union -  To merge components containing p and q,
 *          set the id of p's root to the id of q's root.
 *
 */

void UF::union_UF(int p, int q){
  this->N[this->root(p)] = this->root(q);
}
