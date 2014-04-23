/*------------------------------------------*/
/*   Structures Describing Bonding   */
/* Structure:41:BondOrderMatrix

                     Size --(INT) Number of Columns , Rows
                TotalSize --(INT) Total Size of Matrix
                   Matrix --(INT) The Matrix Array
*/
typedef struct bondordermatrix BondOrderMatrix;
struct bondordermatrix {
     INT ID;
     CHAR *Name;
     INT  Size;
     INT  TotalSize;
     INT *Matrix;
     };
#define BondOrderMatrixSize sizeof(BondOrderMatrix)
#define AllocateBondOrderMatrix (BondOrderMatrix *) Malloc(BondOrderMatrixSize)
#define AllocArrayBondOrderMatrix(n) (BondOrderMatrix *) Calloc(n,BondOrderMatrixSize)
#define BondOrderMatrixPntrSize sizeof(BondOrderMatrix **)
#define AllocPntrArrayBondOrderMatrix(n) (BondOrderMatrix **) Calloc(n,BondOrderMatrixPntrSize)
#define SingCopyBondOrderMatrix(out,in) memcpy(out,in,BondOrderMatrixSize)
extern BondOrderMatrix *CreateBondOrderMatrix(BondOrderMatrix *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  Size,
                                       INT  TotalSize,
                                       INT *Matrix);

extern CHAR *GetNameBondOrderMatrix(BondOrderMatrix *str);
extern INT  GetIDBondOrderMatrix(BondOrderMatrix *str);
extern void PrintBondOrderMatrix(BondOrderMatrix *eleptr);
extern void FreeBondOrderMatrix(BondOrderMatrix *eleptr);
extern void *AllocBondOrderMatrix();
extern void WriteBinBondOrderMatrix(BondOrderMatrix *eleptr, DbaseLinkedList *file);
extern INT ReadBinBondOrderMatrix(BondOrderMatrix *eleptr, DbaseLinkedList *file);
extern void xdr_BondOrderMatrix(XDR *stream, char **eleptr);
extern void CopyFullBondOrderMatrix(BondOrderMatrix *newstruct, BondOrderMatrix *oldstruct);
