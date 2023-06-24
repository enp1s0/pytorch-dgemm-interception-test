import torch

A = torch.randn(300, 400, dtype=torch.float64)
B = torch.randn(400, 400, dtype=torch.float64)

C = torch.matmul(A, B)
