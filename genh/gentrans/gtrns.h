/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:300:GraphNode

                 Molecule --(INT) Position of Molecule Within List
                    GNode --(INT) Position of node within Molecule
*/
typedef struct graphnode GraphNode;
struct graphnode {
     INT ID;
     CHAR *Name;
     INT  Molecule;
     INT  GNode;
     };
#define GraphNodeSize sizeof(GraphNode)
#define AllocateGraphNode (GraphNode *) Malloc(GraphNodeSize)
#define AllocArrayGraphNode(n) (GraphNode *) Calloc(n,GraphNodeSize)
#define GraphNodePntrSize sizeof(GraphNode **)
#define AllocPntrArrayGraphNode(n) (GraphNode **) Calloc(n,GraphNodePntrSize)
#define SingCopyGraphNode(out,in) memcpy(out,in,GraphNodeSize)
extern GraphNode *CreateGraphNode(GraphNode *newstruct,
                           INT id,
                           CHAR *name,
                           INT  Molecule,
                           INT  GNode);

extern CHAR *GetNameGraphNode(GraphNode *str);
extern INT  GetIDGraphNode(GraphNode *str);
extern void PrintGraphNode(GraphNode *eleptr);
extern void FreeGraphNode(GraphNode *eleptr);
extern void *AllocGraphNode();
extern void WriteBinGraphNode(GraphNode *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraphNode(GraphNode *eleptr, DbaseLinkedList *file);
extern void xdr_GraphNode(XDR *stream, char **eleptr);
extern void CopyFullGraphNode(GraphNode *newstruct, GraphNode *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:301:GraphNodePair

               TransformN --(GraphNode) Transform Node
                   GraphN --(GraphNode) Graph Node
*/
typedef struct graphnodepair GraphNodePair;
struct graphnodepair {
     INT ID;
     CHAR *Name;
     GraphNode *TransformN;
     GraphNode *GraphN;
     };
#define GraphNodePairSize sizeof(GraphNodePair)
#define AllocateGraphNodePair (GraphNodePair *) Malloc(GraphNodePairSize)
#define AllocArrayGraphNodePair(n) (GraphNodePair *) Calloc(n,GraphNodePairSize)
#define GraphNodePairPntrSize sizeof(GraphNodePair **)
#define AllocPntrArrayGraphNodePair(n) (GraphNodePair **) Calloc(n,GraphNodePairPntrSize)
#define SingCopyGraphNodePair(out,in) memcpy(out,in,GraphNodePairSize)
extern GraphNodePair *CreateGraphNodePair(GraphNodePair *newstruct,
                                   INT id,
                                   CHAR *name,
                                   GraphNode *TransformN,
                                   GraphNode *GraphN);

extern CHAR *GetNameGraphNodePair(GraphNodePair *str);
extern INT  GetIDGraphNodePair(GraphNodePair *str);
extern void PrintGraphNodePair(GraphNodePair *eleptr);
extern void FreeGraphNodePair(GraphNodePair *eleptr);
extern void *AllocGraphNodePair();
extern void WriteBinGraphNodePair(GraphNodePair *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraphNodePair(GraphNodePair *eleptr, DbaseLinkedList *file);
extern void xdr_GraphNodePair(XDR *stream, char **eleptr);
extern void CopyFullGraphNodePair(GraphNodePair *newstruct, GraphNodePair *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:301:GraphBond

                MoleculeI --(INT) Position of Molecule Within List
                   GNodeI --(INT) Position of first node within Molecule
                MoleculeJ --(INT) Position of Molecule Within List
                   GNodeJ --(INT) Position of second node within molecule
                     Type --(INT) The Type of Bond change
*/
typedef struct graphbond GraphBond;
struct graphbond {
     INT ID;
     CHAR *Name;
     INT  MoleculeI;
     INT  GNodeI;
     INT  MoleculeJ;
     INT  GNodeJ;
     INT  Type;
     };
#define GraphBondSize sizeof(GraphBond)
#define AllocateGraphBond (GraphBond *) Malloc(GraphBondSize)
#define AllocArrayGraphBond(n) (GraphBond *) Calloc(n,GraphBondSize)
#define GraphBondPntrSize sizeof(GraphBond **)
#define AllocPntrArrayGraphBond(n) (GraphBond **) Calloc(n,GraphBondPntrSize)
#define SingCopyGraphBond(out,in) memcpy(out,in,GraphBondSize)
extern GraphBond *CreateGraphBond(GraphBond *newstruct,
                           INT id,
                           CHAR *name,
                           INT  MoleculeI,
                           INT  GNodeI,
                           INT  MoleculeJ,
                           INT  GNodeJ,
                           INT  Type);

extern CHAR *GetNameGraphBond(GraphBond *str);
extern INT  GetIDGraphBond(GraphBond *str);
extern void PrintGraphBond(GraphBond *eleptr);
extern void FreeGraphBond(GraphBond *eleptr);
extern void *AllocGraphBond();
extern void WriteBinGraphBond(GraphBond *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraphBond(GraphBond *eleptr, DbaseLinkedList *file);
extern void xdr_GraphBond(XDR *stream, char **eleptr);
extern void CopyFullGraphBond(GraphBond *newstruct, GraphBond *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:302:NodeTransform

                  LHSnode --(GraphNode) The node on the Left Hand Side
                  RHSnode --(GraphNode) The node on the Right Hand Side
*/
typedef struct nodetransform NodeTransform;
struct nodetransform {
     INT ID;
     CHAR *Name;
     GraphNode *LHSnode;
     GraphNode *RHSnode;
     };
#define NodeTransformSize sizeof(NodeTransform)
#define AllocateNodeTransform (NodeTransform *) Malloc(NodeTransformSize)
#define AllocArrayNodeTransform(n) (NodeTransform *) Calloc(n,NodeTransformSize)
#define NodeTransformPntrSize sizeof(NodeTransform **)
#define AllocPntrArrayNodeTransform(n) (NodeTransform **) Calloc(n,NodeTransformPntrSize)
#define SingCopyNodeTransform(out,in) memcpy(out,in,NodeTransformSize)
extern NodeTransform *CreateNodeTransform(NodeTransform *newstruct,
                                   INT id,
                                   CHAR *name,
                                   GraphNode *LHSnode,
                                   GraphNode *RHSnode);

extern CHAR *GetNameNodeTransform(NodeTransform *str);
extern INT  GetIDNodeTransform(NodeTransform *str);
extern void PrintNodeTransform(NodeTransform *eleptr);
extern void FreeNodeTransform(NodeTransform *eleptr);
extern void *AllocNodeTransform();
extern void WriteBinNodeTransform(NodeTransform *eleptr, DbaseLinkedList *file);
extern INT ReadBinNodeTransform(NodeTransform *eleptr, DbaseLinkedList *file);
extern void xdr_NodeTransform(XDR *stream, char **eleptr);
extern void CopyFullNodeTransform(NodeTransform *newstruct, NodeTransform *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:303:SetOfNodeTransforms

     NumberOfNodeTransforms --(INT) Number Of Nodes that are transformed
               Transforms --(NodeTransform) The Set of transforms
         NumberRUnmatched --(INT) The number of unmatched atoms
               RUnmatched --(GraphNode) The set of Unmatched Reactant Atoms
         NumberPUnmatched --(INT) The number of unmatched atoms
               PUnmatched --(GraphNode) The set of Unmatched Product Atoms
*/
typedef struct setofnodetransforms SetOfNodeTransforms;
struct setofnodetransforms {
     INT ID;
     CHAR *Name;
     INT  NumberOfNodeTransforms;
     NodeTransform *Transforms;
     INT  NumberRUnmatched;
     GraphNode *RUnmatched;
     INT  NumberPUnmatched;
     GraphNode *PUnmatched;
     };
#define SetOfNodeTransformsSize sizeof(SetOfNodeTransforms)
#define AllocateSetOfNodeTransforms (SetOfNodeTransforms *) Malloc(SetOfNodeTransformsSize)
#define AllocArraySetOfNodeTransforms(n) (SetOfNodeTransforms *) Calloc(n,SetOfNodeTransformsSize)
#define SetOfNodeTransformsPntrSize sizeof(SetOfNodeTransforms **)
#define AllocPntrArraySetOfNodeTransforms(n) (SetOfNodeTransforms **) Calloc(n,SetOfNodeTransformsPntrSize)
#define SingCopySetOfNodeTransforms(out,in) memcpy(out,in,SetOfNodeTransformsSize)
extern SetOfNodeTransforms *CreateSetOfNodeTransforms(SetOfNodeTransforms *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfNodeTransforms,
                                               NodeTransform *Transforms,
                                               INT  NumberRUnmatched,
                                               GraphNode *RUnmatched,
                                               INT  NumberPUnmatched,
                                               GraphNode *PUnmatched);

extern CHAR *GetNameSetOfNodeTransforms(SetOfNodeTransforms *str);
extern INT  GetIDSetOfNodeTransforms(SetOfNodeTransforms *str);
extern void PrintSetOfNodeTransforms(SetOfNodeTransforms *eleptr);
extern void FreeSetOfNodeTransforms(SetOfNodeTransforms *eleptr);
extern void *AllocSetOfNodeTransforms();
extern void WriteBinSetOfNodeTransforms(SetOfNodeTransforms *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfNodeTransforms(SetOfNodeTransforms *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfNodeTransforms(XDR *stream, char **eleptr);
extern void CopyFullSetOfNodeTransforms(SetOfNodeTransforms *newstruct, SetOfNodeTransforms *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:304:BondTransforms

        NumberOfBondsMade --(INT) The number of bonds bonds made
                BondsMade --(GraphBond) The Made Bonds
      NumberOfBondsBroken --(INT) The number of bond broken
              BondsBroken --(GraphBond) The Broken Bonds
*/
typedef struct bondtransforms BondTransforms;
struct bondtransforms {
     INT ID;
     CHAR *Name;
     INT  NumberOfBondsMade;
     GraphBond *BondsMade;
     INT  NumberOfBondsBroken;
     GraphBond *BondsBroken;
     };
#define BondTransformsSize sizeof(BondTransforms)
#define AllocateBondTransforms (BondTransforms *) Malloc(BondTransformsSize)
#define AllocArrayBondTransforms(n) (BondTransforms *) Calloc(n,BondTransformsSize)
#define BondTransformsPntrSize sizeof(BondTransforms **)
#define AllocPntrArrayBondTransforms(n) (BondTransforms **) Calloc(n,BondTransformsPntrSize)
#define SingCopyBondTransforms(out,in) memcpy(out,in,BondTransformsSize)
extern BondTransforms *CreateBondTransforms(BondTransforms *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfBondsMade,
                                     GraphBond *BondsMade,
                                     INT  NumberOfBondsBroken,
                                     GraphBond *BondsBroken);

extern CHAR *GetNameBondTransforms(BondTransforms *str);
extern INT  GetIDBondTransforms(BondTransforms *str);
extern void PrintBondTransforms(BondTransforms *eleptr);
extern void FreeBondTransforms(BondTransforms *eleptr);
extern void *AllocBondTransforms();
extern void WriteBinBondTransforms(BondTransforms *eleptr, DbaseLinkedList *file);
extern INT ReadBinBondTransforms(BondTransforms *eleptr, DbaseLinkedList *file);
extern void xdr_BondTransforms(XDR *stream, char **eleptr);
extern void CopyFullBondTransforms(BondTransforms *newstruct, BondTransforms *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:305:BondTransformSet

             LHStransform --(BondTransforms) The bonds on the LHS that are present but not on RHS
             RHStransform --(BondTransforms) The bonds on the RHS that are present but not on LHS
*/
typedef struct bondtransformset BondTransformSet;
struct bondtransformset {
     INT ID;
     CHAR *Name;
     BondTransforms *LHStransform;
     BondTransforms *RHStransform;
     };
#define BondTransformSetSize sizeof(BondTransformSet)
#define AllocateBondTransformSet (BondTransformSet *) Malloc(BondTransformSetSize)
#define AllocArrayBondTransformSet(n) (BondTransformSet *) Calloc(n,BondTransformSetSize)
#define BondTransformSetPntrSize sizeof(BondTransformSet **)
#define AllocPntrArrayBondTransformSet(n) (BondTransformSet **) Calloc(n,BondTransformSetPntrSize)
#define SingCopyBondTransformSet(out,in) memcpy(out,in,BondTransformSetSize)
extern BondTransformSet *CreateBondTransformSet(BondTransformSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         BondTransforms *LHStransform,
                                         BondTransforms *RHStransform);

extern CHAR *GetNameBondTransformSet(BondTransformSet *str);
extern INT  GetIDBondTransformSet(BondTransformSet *str);
extern void PrintBondTransformSet(BondTransformSet *eleptr);
extern void FreeBondTransformSet(BondTransformSet *eleptr);
extern void *AllocBondTransformSet();
extern void WriteBinBondTransformSet(BondTransformSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinBondTransformSet(BondTransformSet *eleptr, DbaseLinkedList *file);
extern void xdr_BondTransformSet(XDR *stream, char **eleptr);
extern void CopyFullBondTransformSet(BondTransformSet *newstruct, BondTransformSet *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:306:GraphTransform

                NumberLHS --(INT) The number of Graphs on the LHS
                NumberRHS --(INT) The number of Graphs on the RHS
                 GraphLHS --(Graph) The set of graphs on the LHS
                 GraphRHS --(Graph) The set of graphs on the RHS
                    Nodes --(SetOfNodeTransforms) The Node Transforms
                    Bonds --(BondTransformSet) The Bond Transforms
*/
typedef struct graphtransform GraphTransform;
struct graphtransform {
     INT ID;
     CHAR *Name;
     INT  NumberLHS;
     INT  NumberRHS;
     Graph *GraphLHS;
     Graph *GraphRHS;
     SetOfNodeTransforms *Nodes;
     BondTransformSet *Bonds;
     };
#define GraphTransformSize sizeof(GraphTransform)
#define AllocateGraphTransform (GraphTransform *) Malloc(GraphTransformSize)
#define AllocArrayGraphTransform(n) (GraphTransform *) Calloc(n,GraphTransformSize)
#define GraphTransformPntrSize sizeof(GraphTransform **)
#define AllocPntrArrayGraphTransform(n) (GraphTransform **) Calloc(n,GraphTransformPntrSize)
#define SingCopyGraphTransform(out,in) memcpy(out,in,GraphTransformSize)
extern GraphTransform *CreateGraphTransform(GraphTransform *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberLHS,
                                     INT  NumberRHS,
                                     Graph *GraphLHS,
                                     Graph *GraphRHS,
                                     SetOfNodeTransforms *Nodes,
                                     BondTransformSet *Bonds);

extern CHAR *GetNameGraphTransform(GraphTransform *str);
extern INT  GetIDGraphTransform(GraphTransform *str);
extern void PrintGraphTransform(GraphTransform *eleptr);
extern void FreeGraphTransform(GraphTransform *eleptr);
extern void *AllocGraphTransform();
extern void WriteBinGraphTransform(GraphTransform *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraphTransform(GraphTransform *eleptr, DbaseLinkedList *file);
extern void xdr_GraphTransform(XDR *stream, char **eleptr);
extern void CopyFullGraphTransform(GraphTransform *newstruct, GraphTransform *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:307:TransformGraphCorrSet

           NumberOfGraphs --(INT) The number of graphs in the transform
         TransformPairSet --(SetOfPairSets) The SetOfPairSets for each transform graph
*/
typedef struct transformgraphcorrset TransformGraphCorrSet;
struct transformgraphcorrset {
     INT ID;
     CHAR *Name;
     INT  NumberOfGraphs;
     SetOfPairSets *TransformPairSet;
     };
#define TransformGraphCorrSetSize sizeof(TransformGraphCorrSet)
#define AllocateTransformGraphCorrSet (TransformGraphCorrSet *) Malloc(TransformGraphCorrSetSize)
#define AllocArrayTransformGraphCorrSet(n) (TransformGraphCorrSet *) Calloc(n,TransformGraphCorrSetSize)
#define TransformGraphCorrSetPntrSize sizeof(TransformGraphCorrSet **)
#define AllocPntrArrayTransformGraphCorrSet(n) (TransformGraphCorrSet **) Calloc(n,TransformGraphCorrSetPntrSize)
#define SingCopyTransformGraphCorrSet(out,in) memcpy(out,in,TransformGraphCorrSetSize)
extern TransformGraphCorrSet *CreateTransformGraphCorrSet(TransformGraphCorrSet *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfGraphs,
                                                   SetOfPairSets *TransformPairSet);

extern CHAR *GetNameTransformGraphCorrSet(TransformGraphCorrSet *str);
extern INT  GetIDTransformGraphCorrSet(TransformGraphCorrSet *str);
extern void PrintTransformGraphCorrSet(TransformGraphCorrSet *eleptr);
extern void FreeTransformGraphCorrSet(TransformGraphCorrSet *eleptr);
extern void *AllocTransformGraphCorrSet();
extern void WriteBinTransformGraphCorrSet(TransformGraphCorrSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinTransformGraphCorrSet(TransformGraphCorrSet *eleptr, DbaseLinkedList *file);
extern void xdr_TransformGraphCorrSet(XDR *stream, char **eleptr);
extern void CopyFullTransformGraphCorrSet(TransformGraphCorrSet *newstruct, TransformGraphCorrSet *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:306:GraphTransformGraphTree

                 CorrSets --(TransformGraphCorrSet) The set of graph reaction correspondences
         NumberOfSubTrees --(INT) The number of subtrees (total combinations of graphs and corrs)
                  SubTree --(GraphTransformGraphTree) The correspondence subtree
*/
typedef struct graphtransformgraphtree GraphTransformGraphTree;
struct graphtransformgraphtree {
     INT ID;
     CHAR *Name;
     TransformGraphCorrSet *CorrSets;
     INT  NumberOfSubTrees;
     GraphTransformGraphTree *SubTree;
     };
#define GraphTransformGraphTreeSize sizeof(GraphTransformGraphTree)
#define AllocateGraphTransformGraphTree (GraphTransformGraphTree *) Malloc(GraphTransformGraphTreeSize)
#define AllocArrayGraphTransformGraphTree(n) (GraphTransformGraphTree *) Calloc(n,GraphTransformGraphTreeSize)
#define GraphTransformGraphTreePntrSize sizeof(GraphTransformGraphTree **)
#define AllocPntrArrayGraphTransformGraphTree(n) (GraphTransformGraphTree **) Calloc(n,GraphTransformGraphTreePntrSize)
#define SingCopyGraphTransformGraphTree(out,in) memcpy(out,in,GraphTransformGraphTreeSize)
extern GraphTransformGraphTree *CreateGraphTransformGraphTree(GraphTransformGraphTree *newstruct,
INT id,
CHAR *name,
TransformGraphCorrSet *CorrSets,
INT  NumberOfSubTrees,
GraphTransformGraphTree *SubTree);

extern CHAR *GetNameGraphTransformGraphTree(GraphTransformGraphTree *str);
extern INT  GetIDGraphTransformGraphTree(GraphTransformGraphTree *str);
extern void PrintGraphTransformGraphTree(GraphTransformGraphTree *eleptr);
extern void FreeGraphTransformGraphTree(GraphTransformGraphTree *eleptr);
extern void *AllocGraphTransformGraphTree();
extern void WriteBinGraphTransformGraphTree(GraphTransformGraphTree *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraphTransformGraphTree(GraphTransformGraphTree *eleptr, DbaseLinkedList *file);
extern void xdr_GraphTransformGraphTree(XDR *stream, char **eleptr);
extern void CopyFullGraphTransformGraphTree(GraphTransformGraphTree *newstruct, GraphTransformGraphTree *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:307:TransformSet

       NumberOfTransforms --(INT) The number of Transforms
                      Set --(GraphTransform) The set of Transforms
*/
typedef struct transformset TransformSet;
struct transformset {
     INT ID;
     CHAR *Name;
     INT  NumberOfTransforms;
     GraphTransform *Set;
     };
#define TransformSetSize sizeof(TransformSet)
#define AllocateTransformSet (TransformSet *) Malloc(TransformSetSize)
#define AllocArrayTransformSet(n) (TransformSet *) Calloc(n,TransformSetSize)
#define TransformSetPntrSize sizeof(TransformSet **)
#define AllocPntrArrayTransformSet(n) (TransformSet **) Calloc(n,TransformSetPntrSize)
#define SingCopyTransformSet(out,in) memcpy(out,in,TransformSetSize)
extern TransformSet *CreateTransformSet(TransformSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfTransforms,
                                 GraphTransform *Set);

extern CHAR *GetNameTransformSet(TransformSet *str);
extern INT  GetIDTransformSet(TransformSet *str);
extern void PrintTransformSet(TransformSet *eleptr);
extern void FreeTransformSet(TransformSet *eleptr);
extern void *AllocTransformSet();
extern void WriteBinTransformSet(TransformSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinTransformSet(TransformSet *eleptr, DbaseLinkedList *file);
extern void xdr_TransformSet(XDR *stream, char **eleptr);
extern void CopyFullTransformSet(TransformSet *newstruct, TransformSet *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:311:SetOfGraphNodePairs

            NumberOfPairs --(INT) The Number Of GraphNodePairs
                    Pairs --(GraphNodePair) The Set of GraphNOdePairs
*/
typedef struct setofgraphnodepairs SetOfGraphNodePairs;
struct setofgraphnodepairs {
     INT ID;
     CHAR *Name;
     INT  NumberOfPairs;
     GraphNodePair *Pairs;
     };
#define SetOfGraphNodePairsSize sizeof(SetOfGraphNodePairs)
#define AllocateSetOfGraphNodePairs (SetOfGraphNodePairs *) Malloc(SetOfGraphNodePairsSize)
#define AllocArraySetOfGraphNodePairs(n) (SetOfGraphNodePairs *) Calloc(n,SetOfGraphNodePairsSize)
#define SetOfGraphNodePairsPntrSize sizeof(SetOfGraphNodePairs **)
#define AllocPntrArraySetOfGraphNodePairs(n) (SetOfGraphNodePairs **) Calloc(n,SetOfGraphNodePairsPntrSize)
#define SingCopySetOfGraphNodePairs(out,in) memcpy(out,in,SetOfGraphNodePairsSize)
extern SetOfGraphNodePairs *CreateSetOfGraphNodePairs(SetOfGraphNodePairs *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfPairs,
                                               GraphNodePair *Pairs);

extern CHAR *GetNameSetOfGraphNodePairs(SetOfGraphNodePairs *str);
extern INT  GetIDSetOfGraphNodePairs(SetOfGraphNodePairs *str);
extern void PrintSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr);
extern void FreeSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr);
extern void *AllocSetOfGraphNodePairs();
extern void WriteBinSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfGraphNodePairs(XDR *stream, char **eleptr);
extern void CopyFullSetOfGraphNodePairs(SetOfGraphNodePairs *newstruct, SetOfGraphNodePairs *oldstruct);
/*------------------------------------------*/
/*   Graph Transformation Structures   */
/* Structure:312:TotalSetOfTransformPairs

         NumberOfPairSets --(INT) The Number Of Sets
                 PairSets --(SetOfGraphNodePairs) The Pair Sets
*/
typedef struct totalsetoftransformpairs TotalSetOfTransformPairs;
struct totalsetoftransformpairs {
     INT ID;
     CHAR *Name;
     INT  NumberOfPairSets;
     SetOfGraphNodePairs *PairSets;
     };
#define TotalSetOfTransformPairsSize sizeof(TotalSetOfTransformPairs)
#define AllocateTotalSetOfTransformPairs (TotalSetOfTransformPairs *) Malloc(TotalSetOfTransformPairsSize)
#define AllocArrayTotalSetOfTransformPairs(n) (TotalSetOfTransformPairs *) Calloc(n,TotalSetOfTransformPairsSize)
#define TotalSetOfTransformPairsPntrSize sizeof(TotalSetOfTransformPairs **)
#define AllocPntrArrayTotalSetOfTransformPairs(n) (TotalSetOfTransformPairs **) Calloc(n,TotalSetOfTransformPairsPntrSize)
#define SingCopyTotalSetOfTransformPairs(out,in) memcpy(out,in,TotalSetOfTransformPairsSize)
extern TotalSetOfTransformPairs *CreateTotalSetOfTransformPairs(TotalSetOfTransformPairs *newstruct,
INT id,
CHAR *name,
INT  NumberOfPairSets,
SetOfGraphNodePairs *PairSets);

extern CHAR *GetNameTotalSetOfTransformPairs(TotalSetOfTransformPairs *str);
extern INT  GetIDTotalSetOfTransformPairs(TotalSetOfTransformPairs *str);
extern void PrintTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr);
extern void FreeTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr);
extern void *AllocTotalSetOfTransformPairs();
extern void WriteBinTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr, DbaseLinkedList *file);
extern INT ReadBinTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr, DbaseLinkedList *file);
extern void xdr_TotalSetOfTransformPairs(XDR *stream, char **eleptr);
extern void CopyFullTotalSetOfTransformPairs(TotalSetOfTransformPairs *newstruct, TotalSetOfTransformPairs *oldstruct);
