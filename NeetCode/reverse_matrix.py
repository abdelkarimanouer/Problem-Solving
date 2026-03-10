def reverse_matrix(matrix: list[list[int]]) -> list[list[int]]:
    for m in matrix:
        m.reverse()
    matrix.reverse()
    return matrix
