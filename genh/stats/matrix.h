/*------------------------------------------*/
/*   Structures for the Matrix   Routines   */
/* Structure:51:FullMatrixFLT

                     Dim1 --(INT) The number of Rows
                     Dim2 --(INT) The number of Columns
                 TotalDim --(INT) The total Dimension
                 Elements --(FLOAT) The Array as Vector of Floating Points
*/
typedef struct fullmatrix FullMatrixFLT;
struct fullmatrix {
     INT ID;
     CHAR *Name;
     INT  Dim1;
     INT  Dim2;
     INT  TotalDim;
     FLOAT *Elements;
     };
#define FullMatrixFLTSize sizeof(FullMatrixFLT)
#define AllocateFullMatrixFLT (FullMatrixFLT *) Malloc(FullMatrixFLTSize)
#define AllocArrayFullMatrixFLT(n) (FullMatrixFLT *) Calloc(n,FullMatrixFLTSize)
#define FullMatrixFLTPntrSize sizeof(FullMatrixFLT **)
#define AllocPntrArrayFullMatrixFLT(n) (FullMatrixFLT **) Calloc(n,FullMatrixFLTPntrSize)
#define SingCopyFullMatrixFLT(out,in) memcpy(out,in,FullMatrixFLTSize)
extern FullMatrixFLT *CreateFullMatrixFLT(FullMatrixFLT *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  Dim1,
                                   INT  Dim2,
                                   INT  TotalDim,
                                   FLOAT *Elements);

extern CHAR *GetNameFullMatrixFLT(FullMatrixFLT *str);
extern INT  GetIDFullMatrixFLT(FullMatrixFLT *str);
extern void PrintFullMatrixFLT(FullMatrixFLT *eleptr);
extern void FreeFullMatrixFLT(FullMatrixFLT *eleptr);
extern void *AllocFullMatrixFLT();
extern void WriteBinFullMatrixFLT(FullMatrixFLT *eleptr, DbaseLinkedList *file);
extern INT ReadBinFullMatrixFLT(FullMatrixFLT *eleptr, DbaseLinkedList *file);
extern void xdr_FullMatrixFLT(XDR *stream, char **eleptr);
extern void CopyFullFullMatrixFLT(FullMatrixFLT *newstruct, FullMatrixFLT *oldstruct);
/*------------------------------------------*/
/*   Structures for the Matrix   Routines   */
/* Structure:52:SymmetricEigenMath

             NumberOfRows --(INT) The number of rows
                 Elements --(FullMatrixFLT) The matrix of elements
              Eigenvalues --(FLOAT) The eigenvalues
             Eigenvectors --(FullMatrixFLT) The Eigenvectors
*/
typedef struct symeigen SymmetricEigenMath;
struct symeigen {
     INT ID;
     CHAR *Name;
     INT  NumberOfRows;
     FullMatrixFLT *Elements;
     FLOAT *Eigenvalues;
     FullMatrixFLT *Eigenvectors;
     };
#define SymmetricEigenMathSize sizeof(SymmetricEigenMath)
#define AllocateSymmetricEigenMath (SymmetricEigenMath *) Malloc(SymmetricEigenMathSize)
#define AllocArraySymmetricEigenMath(n) (SymmetricEigenMath *) Calloc(n,SymmetricEigenMathSize)
#define SymmetricEigenMathPntrSize sizeof(SymmetricEigenMath **)
#define AllocPntrArraySymmetricEigenMath(n) (SymmetricEigenMath **) Calloc(n,SymmetricEigenMathPntrSize)
#define SingCopySymmetricEigenMath(out,in) memcpy(out,in,SymmetricEigenMathSize)
extern SymmetricEigenMath *CreateSymmetricEigenMath(SymmetricEigenMath *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfRows,
                                             FullMatrixFLT *Elements,
                                             FLOAT *Eigenvalues,
                                             FullMatrixFLT *Eigenvectors);

extern CHAR *GetNameSymmetricEigenMath(SymmetricEigenMath *str);
extern INT  GetIDSymmetricEigenMath(SymmetricEigenMath *str);
extern void PrintSymmetricEigenMath(SymmetricEigenMath *eleptr);
extern void FreeSymmetricEigenMath(SymmetricEigenMath *eleptr);
extern void *AllocSymmetricEigenMath();
extern void WriteBinSymmetricEigenMath(SymmetricEigenMath *eleptr, DbaseLinkedList *file);
extern INT ReadBinSymmetricEigenMath(SymmetricEigenMath *eleptr, DbaseLinkedList *file);
extern void xdr_SymmetricEigenMath(XDR *stream, char **eleptr);
extern void CopyFullSymmetricEigenMath(SymmetricEigenMath *newstruct, SymmetricEigenMath *oldstruct);
