/*------------------------------------------*/
/*   Structures for Pair Correlations   */
/* Structure:40:Pair

                        I --(INT) The first in the pair
                        J --(INT) The second in the pair
*/
typedef struct pairelement Pair;
struct pairelement {
     INT ID;
     CHAR *Name;
     INT  I;
     INT  J;
     };
#define PairSize sizeof(Pair)
#define AllocatePair (Pair *) Malloc(PairSize)
#define AllocArrayPair(n) (Pair *) Calloc(n,PairSize)
#define PairPntrSize sizeof(Pair **)
#define AllocPntrArrayPair(n) (Pair **) Calloc(n,PairPntrSize)
#define SingCopyPair(out,in) memcpy(out,in,PairSize)
extern Pair *CreatePair(Pair *newstruct,
                 INT id,
                 CHAR *name,
                 INT  I,
                 INT  J);

extern CHAR *GetNamePair(Pair *str);
extern INT  GetIDPair(Pair *str);
extern void PrintPair(Pair *eleptr);
extern void FreePair(Pair *eleptr);
extern void *AllocPair();
extern void WriteBinPair(Pair *eleptr, DbaseLinkedList *file);
extern INT ReadBinPair(Pair *eleptr, DbaseLinkedList *file);
extern void xdr_Pair(XDR *stream, char **eleptr);
extern void CopyFullPair(Pair *newstruct, Pair *oldstruct);
/*------------------------------------------*/
/*   Structures for Pair Correlations   */
/* Structure:41:PairSet

            NumberOfPairs --(INT) The Number of Pairs
                    Pairs --(Pair) The set of Pairs
*/
typedef struct pairset PairSet;
struct pairset {
     INT ID;
     CHAR *Name;
     INT  NumberOfPairs;
     Pair *Pairs;
     };
#define PairSetSize sizeof(PairSet)
#define AllocatePairSet (PairSet *) Malloc(PairSetSize)
#define AllocArrayPairSet(n) (PairSet *) Calloc(n,PairSetSize)
#define PairSetPntrSize sizeof(PairSet **)
#define AllocPntrArrayPairSet(n) (PairSet **) Calloc(n,PairSetPntrSize)
#define SingCopyPairSet(out,in) memcpy(out,in,PairSetSize)
extern PairSet *CreatePairSet(PairSet *newstruct,
                       INT id,
                       CHAR *name,
                       INT  NumberOfPairs,
                       Pair *Pairs);

extern CHAR *GetNamePairSet(PairSet *str);
extern INT  GetIDPairSet(PairSet *str);
extern void PrintPairSet(PairSet *eleptr);
extern void FreePairSet(PairSet *eleptr);
extern void *AllocPairSet();
extern void WriteBinPairSet(PairSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinPairSet(PairSet *eleptr, DbaseLinkedList *file);
extern void xdr_PairSet(XDR *stream, char **eleptr);
extern void CopyFullPairSet(PairSet *newstruct, PairSet *oldstruct);
/*------------------------------------------*/
/*   Structures for Pair Correlations   */
/* Structure:42:SetOfPairSets

             NumberOfSets --(INT) The Number of sets
                     Sets --(PairSet) The set of PairSets
*/
typedef struct setofpairsets SetOfPairSets;
struct setofpairsets {
     INT ID;
     CHAR *Name;
     INT  NumberOfSets;
     PairSet *Sets;
     };
#define SetOfPairSetsSize sizeof(SetOfPairSets)
#define AllocateSetOfPairSets (SetOfPairSets *) Malloc(SetOfPairSetsSize)
#define AllocArraySetOfPairSets(n) (SetOfPairSets *) Calloc(n,SetOfPairSetsSize)
#define SetOfPairSetsPntrSize sizeof(SetOfPairSets **)
#define AllocPntrArraySetOfPairSets(n) (SetOfPairSets **) Calloc(n,SetOfPairSetsPntrSize)
#define SingCopySetOfPairSets(out,in) memcpy(out,in,SetOfPairSetsSize)
extern SetOfPairSets *CreateSetOfPairSets(SetOfPairSets *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfSets,
                                   PairSet *Sets);

extern CHAR *GetNameSetOfPairSets(SetOfPairSets *str);
extern INT  GetIDSetOfPairSets(SetOfPairSets *str);
extern void PrintSetOfPairSets(SetOfPairSets *eleptr);
extern void FreeSetOfPairSets(SetOfPairSets *eleptr);
extern void *AllocSetOfPairSets();
extern void WriteBinSetOfPairSets(SetOfPairSets *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfPairSets(SetOfPairSets *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfPairSets(XDR *stream, char **eleptr);
extern void CopyFullSetOfPairSets(SetOfPairSets *newstruct, SetOfPairSets *oldstruct);
/*------------------------------------------*/
/*   Structures for Pair Correlations   */
/* Structure:53:DataSetPair

                     Set1 --(DataSubSet) The first set in the pair
                     Set2 --(DataSubSet) The second set in the pair
*/
typedef struct datasetpair DataSetPair;
struct datasetpair {
     INT ID;
     CHAR *Name;
     DataSubSet *Set1;
     DataSubSet *Set2;
     };
#define DataSetPairSize sizeof(DataSetPair)
#define AllocateDataSetPair (DataSetPair *) Malloc(DataSetPairSize)
#define AllocArrayDataSetPair(n) (DataSetPair *) Calloc(n,DataSetPairSize)
#define DataSetPairPntrSize sizeof(DataSetPair **)
#define AllocPntrArrayDataSetPair(n) (DataSetPair **) Calloc(n,DataSetPairPntrSize)
#define SingCopyDataSetPair(out,in) memcpy(out,in,DataSetPairSize)
extern DataSetPair *CreateDataSetPair(DataSetPair *newstruct,
                               INT id,
                               CHAR *name,
                               DataSubSet *Set1,
                               DataSubSet *Set2);

extern CHAR *GetNameDataSetPair(DataSetPair *str);
extern INT  GetIDDataSetPair(DataSetPair *str);
extern void PrintDataSetPair(DataSetPair *eleptr);
extern void FreeDataSetPair(DataSetPair *eleptr);
extern void *AllocDataSetPair();
extern void WriteBinDataSetPair(DataSetPair *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataSetPair(DataSetPair *eleptr, DbaseLinkedList *file);
extern void xdr_DataSetPair(XDR *stream, char **eleptr);
extern void CopyFullDataSetPair(DataSetPair *newstruct, DataSetPair *oldstruct);
/*------------------------------------------*/
/*   Structures for Pair Correlations   */
/* Structure:53:EquivalentSets

             NumberOfSets --(INT) The Number of Sets
                     Sets --(DataSetPair) The set of equivalent sets (sets of DataSetPairs)
*/
typedef struct equivalentsets EquivalentSets;
struct equivalentsets {
     INT ID;
     CHAR *Name;
     INT  NumberOfSets;
     DataSetPair *Sets;
     };
#define EquivalentSetsSize sizeof(EquivalentSets)
#define AllocateEquivalentSets (EquivalentSets *) Malloc(EquivalentSetsSize)
#define AllocArrayEquivalentSets(n) (EquivalentSets *) Calloc(n,EquivalentSetsSize)
#define EquivalentSetsPntrSize sizeof(EquivalentSets **)
#define AllocPntrArrayEquivalentSets(n) (EquivalentSets **) Calloc(n,EquivalentSetsPntrSize)
#define SingCopyEquivalentSets(out,in) memcpy(out,in,EquivalentSetsSize)
extern EquivalentSets *CreateEquivalentSets(EquivalentSets *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfSets,
                                     DataSetPair *Sets);

extern CHAR *GetNameEquivalentSets(EquivalentSets *str);
extern INT  GetIDEquivalentSets(EquivalentSets *str);
extern void PrintEquivalentSets(EquivalentSets *eleptr);
extern void FreeEquivalentSets(EquivalentSets *eleptr);
extern void *AllocEquivalentSets();
extern void WriteBinEquivalentSets(EquivalentSets *eleptr, DbaseLinkedList *file);
extern INT ReadBinEquivalentSets(EquivalentSets *eleptr, DbaseLinkedList *file);
extern void xdr_EquivalentSets(XDR *stream, char **eleptr);
extern void CopyFullEquivalentSets(EquivalentSets *newstruct, EquivalentSets *oldstruct);
