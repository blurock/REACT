/*------------------------------------------*/
/*   Structures for   Factor Analysis   */
/* Structure:53:FactorAnalysis

          NumberOfFactors --(INT) The Number of Factors
                   Cutoff --(FLOAT) The Cutoff used
              Eigenvalues --(FLOAT) The Eigenvalues
                   Vector --(FullMatrixFLT) The Transformation Vector (The eigenvector)
              Coordinates --(FullMatrixFLT) The Transformed Coordinates
*/
typedef struct factoranal FactorAnalysis;
struct factoranal {
     INT ID;
     CHAR *Name;
     INT  NumberOfFactors;
     FLOAT  Cutoff;
     FLOAT *Eigenvalues;
     FullMatrixFLT *Vector;
     FullMatrixFLT *Coordinates;
     };
#define FactorAnalysisSize sizeof(FactorAnalysis)
#define AllocateFactorAnalysis (FactorAnalysis *) Malloc(FactorAnalysisSize)
#define AllocArrayFactorAnalysis(n) (FactorAnalysis *) Calloc(n,FactorAnalysisSize)
#define FactorAnalysisPntrSize sizeof(FactorAnalysis **)
#define AllocPntrArrayFactorAnalysis(n) (FactorAnalysis **) Calloc(n,FactorAnalysisPntrSize)
#define SingCopyFactorAnalysis(out,in) memcpy(out,in,FactorAnalysisSize)
extern FactorAnalysis *CreateFactorAnalysis(FactorAnalysis *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfFactors,
                                     FLOAT  Cutoff,
                                     FLOAT *Eigenvalues,
                                     FullMatrixFLT *Vector,
                                     FullMatrixFLT *Coordinates);

extern CHAR *GetNameFactorAnalysis(FactorAnalysis *str);
extern INT  GetIDFactorAnalysis(FactorAnalysis *str);
extern void PrintFactorAnalysis(FactorAnalysis *eleptr);
extern void FreeFactorAnalysis(FactorAnalysis *eleptr);
extern void *AllocFactorAnalysis();
extern void WriteBinFactorAnalysis(FactorAnalysis *eleptr, DbaseLinkedList *file);
extern INT ReadBinFactorAnalysis(FactorAnalysis *eleptr, DbaseLinkedList *file);
extern void xdr_FactorAnalysis(XDR *stream, char **eleptr);
extern void CopyFullFactorAnalysis(FactorAnalysis *newstruct, FactorAnalysis *oldstruct);
