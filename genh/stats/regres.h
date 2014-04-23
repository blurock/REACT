/*------------------------------------------*/
/*   Structures  for   Regression   */
/* Structure:54:RegressionStat

        NumberOfVariables --(INT) The Number of Variables Removed
              VariableSet --(INT) The variable numbers of those removed
         DegreesOfFreedom --(INT) The Number of Degrees of Freedom
                   SError --(FLOAT) The total error
                 Outliers --(DataSubSet) The set of points over the maximum allowed error
                    FStat --(FLOAT) The F-Statistic
                  Allowed --(FLAG) Allowed Reduction ( 0 = Not allowed, 1 = Allowed )
*/
typedef struct regstat RegressionStat;
struct regstat {
     INT ID;
     CHAR *Name;
     INT  NumberOfVariables;
     INT *VariableSet;
     INT  DegreesOfFreedom;
     FLOAT  SError;
     DataSubSet *Outliers;
     FLOAT  FStat;
     FLAG  Allowed;
     };
#define RegressionStatSize sizeof(RegressionStat)
#define AllocateRegressionStat (RegressionStat *) Malloc(RegressionStatSize)
#define AllocArrayRegressionStat(n) (RegressionStat *) Calloc(n,RegressionStatSize)
#define RegressionStatPntrSize sizeof(RegressionStat **)
#define AllocPntrArrayRegressionStat(n) (RegressionStat **) Calloc(n,RegressionStatPntrSize)
#define SingCopyRegressionStat(out,in) memcpy(out,in,RegressionStatSize)
extern RegressionStat *CreateRegressionStat(RegressionStat *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfVariables,
                                     INT *VariableSet,
                                     INT  DegreesOfFreedom,
                                     FLOAT  SError,
                                     DataSubSet *Outliers,
                                     FLOAT  FStat,
                                     FLAG  Allowed);

extern CHAR *GetNameRegressionStat(RegressionStat *str);
extern INT  GetIDRegressionStat(RegressionStat *str);
extern void PrintRegressionStat(RegressionStat *eleptr);
extern void FreeRegressionStat(RegressionStat *eleptr);
extern void *AllocRegressionStat();
extern void WriteBinRegressionStat(RegressionStat *eleptr, DbaseLinkedList *file);
extern INT ReadBinRegressionStat(RegressionStat *eleptr, DbaseLinkedList *file);
extern void xdr_RegressionStat(XDR *stream, char **eleptr);
extern void CopyFullRegressionStat(RegressionStat *newstruct, RegressionStat *oldstruct);
/*------------------------------------------*/
/*   Structures  for   Regression   */
/* Structure:56:Regression

        NumberOfVariables --(INT) The Number Of Variables
                Variables --(INT) The Set of Variable Numbers
           ResultVariable --(INT) The Variable Number to Predict
                   Points --(DataSubSet) The Set of DataPoints
             AllowedError --(FLOAT) The Maximum Allowed Error
                 Outliers --(DataSubSet) The Set of Points over this error
               TotalError --(FLOAT) The Total Error
             Coefficients --(FullMatrixFLT) The Coefficients
        SysSamVectorSetID --(INT) The SysSamVectorSet ID
*/
typedef struct regression Regression;
struct regression {
     INT ID;
     CHAR *Name;
     INT  NumberOfVariables;
     INT *Variables;
     INT  ResultVariable;
     DataSubSet *Points;
     FLOAT  AllowedError;
     DataSubSet *Outliers;
     FLOAT  TotalError;
     FullMatrixFLT *Coefficients;
     INT  SysSamVectorSetID;
     };
#define RegressionSize sizeof(Regression)
#define AllocateRegression (Regression *) Malloc(RegressionSize)
#define AllocArrayRegression(n) (Regression *) Calloc(n,RegressionSize)
#define RegressionPntrSize sizeof(Regression **)
#define AllocPntrArrayRegression(n) (Regression **) Calloc(n,RegressionPntrSize)
#define SingCopyRegression(out,in) memcpy(out,in,RegressionSize)
extern Regression *CreateRegression(Regression *newstruct,
                             INT id,
                             CHAR *name,
                             INT  NumberOfVariables,
                             INT *Variables,
                             INT  ResultVariable,
                             DataSubSet *Points,
                             FLOAT  AllowedError,
                             DataSubSet *Outliers,
                             FLOAT  TotalError,
                             FullMatrixFLT *Coefficients,
                             INT  SysSamVectorSetID);

extern CHAR *GetNameRegression(Regression *str);
extern INT  GetIDRegression(Regression *str);
extern void PrintRegression(Regression *eleptr);
extern void FreeRegression(Regression *eleptr);
extern void *AllocRegression();
extern void WriteBinRegression(Regression *eleptr, DbaseLinkedList *file);
extern INT ReadBinRegression(Regression *eleptr, DbaseLinkedList *file);
extern void xdr_Regression(XDR *stream, char **eleptr);
extern void CopyFullRegression(Regression *newstruct, Regression *oldstruct);
/*------------------------------------------*/
/*   Structures  for   Regression   */
/* Structure:55:RegressionSet

                 Original --(Regression) The Original Regression
       NumberOfReductions --(INT) The Number of Reductions
          SetOfReductions --(RegressionStat) The Set of Reductions
*/
typedef struct regset RegressionSet;
struct regset {
     INT ID;
     CHAR *Name;
     Regression *Original;
     INT  NumberOfReductions;
     RegressionStat *SetOfReductions;
     };
#define RegressionSetSize sizeof(RegressionSet)
#define AllocateRegressionSet (RegressionSet *) Malloc(RegressionSetSize)
#define AllocArrayRegressionSet(n) (RegressionSet *) Calloc(n,RegressionSetSize)
#define RegressionSetPntrSize sizeof(RegressionSet **)
#define AllocPntrArrayRegressionSet(n) (RegressionSet **) Calloc(n,RegressionSetPntrSize)
#define SingCopyRegressionSet(out,in) memcpy(out,in,RegressionSetSize)
extern RegressionSet *CreateRegressionSet(RegressionSet *newstruct,
                                   INT id,
                                   CHAR *name,
                                   Regression *Original,
                                   INT  NumberOfReductions,
                                   RegressionStat *SetOfReductions);

extern CHAR *GetNameRegressionSet(RegressionSet *str);
extern INT  GetIDRegressionSet(RegressionSet *str);
extern void PrintRegressionSet(RegressionSet *eleptr);
extern void FreeRegressionSet(RegressionSet *eleptr);
extern void *AllocRegressionSet();
extern void WriteBinRegressionSet(RegressionSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinRegressionSet(RegressionSet *eleptr, DbaseLinkedList *file);
extern void xdr_RegressionSet(XDR *stream, char **eleptr);
extern void CopyFullRegressionSet(RegressionSet *newstruct, RegressionSet *oldstruct);
