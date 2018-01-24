/*
 * Dummy (and minimal) function pass to serve as a starting point for your
 * Assignment 2 passes. It simply visits every function and prints every call
 * instruction it finds.
 */

#define DEBUG_TYPE "CONSTPR"
#include "utils.h"

namespace {
    class CONSTPR : public FunctionPass {
    public:
        static char ID;
        CONSTPR() : FunctionPass(ID) {}
        virtual bool runOnFunction(Function &F) override;
    };
}

bool CONSTPR::runOnFunction(Function &F) {
    // Create a worklist of instructions
    std::set<Instruction*> WorkList;
    for (Instruction &I: instructions(&F))
        WorkList.insert(&I);
    bool changed = false;
    while(!WorkList.empty()){
        Instruction *I = *WorkList.begin();
        WorkList.erase(WorkList.begin());    // Get an element from the worklist...
    }




     std::set<Constant> constantSet; //! not using SmallSet, because not certain if can do .begin
    //TODO Map of values(computated numbers) and keys(variable names)

     /*
    for (BasicBlock &BB : F) {
        for (Instruction &II : *BB) {
            Instruction *I = &II;
            if (CallInst *CI = dyn_cast<CallInst>(I)) {
                LOG_LINE(" Found call: " << *CI);
    */

   
    //bool changed
    
    //while(changed)                          // has users (keep looping till nothing is changed)
    while(changed){
    //  changed == false;            
    //  for (each BB in F)
        for (BasicBlock &BB : F) {
    //      for(each I in BB)
            for (Instruction &II : *BB) {
    //          for(each OP in I)
                for(Use &U : &II->operands()){
                    Value *v = U.get();
    //              for(each CONST in OP)  //checks if OP is CONST by casting to ConstantInt
                    if(!(ConstantInt* constantInteger = dyn_cast<ConstantInt>(v)){
                        break;
                    }
                    ConstantInt cInt = dyn_cast<ConstantInt>(v);

                }
    //          for(each OP in I)
                I.getOperandList()           //Inherited user so should have this call
                
    //              for(each CONST in OP) // TODO: Check whether an operand is a constant by casting it to a ConstantInt.
    //                  add CONST to constantSet
    //  end loops
            }
        }

    //  for (each CONST in ConstantSet)
    //      calculate value of constant in order it was added
    //      For every type of computation: lhs.getZExtValue() op rhs.getZEXxtValue()
    //      addition, 
    //      subtraction, 
    //      multiplica- tion, 
    //      arithmetic shift
    //      changed == true      
    //      Insert in map 
    //
    //  go through code and replace if find variable as key in map replace with value
    //
    }



    //bool changed
    //while(changed)                          // has users (keep looping till nothing is changed)
    //  changed == false;            
    //  for (each BB in F)
    //      for(each I in BB)
    //          for(each OP in I)
    //              for(each CONST in OP) // TODO: Check whether an operand is a constant by casting it to a ConstantInt.
    //                  add CONST to constantSet
    //  end loops

        
    //  for (each CONST in ConstantSet)
    //      calculate value of constant in order it was added
    //      For every type of computation: lhs.getZExtValue() op rhs.getZEXxtValue()
    //      addition, 
    //      subtraction, 
    //      multiplica- tion, 
    //      arithmetic shift
    //      changed == true      
    //      Insert in map 
    //
    //  go through code and replace if find variable as key in map replace with value
    //

/*             
        //for (each BB in F)
        for (BasicBlock &BB : F) {
        //  for(each I in BB)  
            for (Instruction &II : BB) {
                Instruction *I = &II;
        //      for(each OP in I)        
                if (CallInst *CI = dyn_cast<ConstantInt>(I)) {
        //TODO add to set          

                }
            }
        }
*/
    //for (each CONST in ConstantSet)
    //  calculate value of constant in order it was added
    //  insert in map 
    //

    //go through code and replace if find variable as key in map replace with value

    return false;  // We did not alter the IR
}

// Register the pass with LLVM so we can invoke it with opt. The first argument
// to RegisterPass is the commandline switch to run this pass (e.g., opt
// -coco-dummypass, the second argument is a description shown in the help text
// about this pass.
char CONSTPR::ID = 0;
static RegisterPass<CONSTPR> X("coco-dummypass", "Example LLVM pass printing each function it visits, and every call instruction it finds");


