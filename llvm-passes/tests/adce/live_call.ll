@.str = private unnamed_addr constant [7 x i8] c"abcdef\00", align 1

define i32 @main() #0 {
  ; CHECK-NOT: %1 = alloca i32, align 4
  %1 = alloca i32, align 4
  ; CHECK: call i32
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str, i32 0, i32 0));
  ret i32 0
}

declare i32 @printf(i8*, ...) #1
