def numOfSubarrays(arr, k, threshold):
    min_sum = k * threshold
    current_sum = sum(arr[:k])
    count = 0

    if current_sum >= min_sum:
        count += 1

    for i in range(k, len(arr)):
        current_sum += arr[i] - arr[i - k]
        if current_sum >= min_sum:
            count += 1

    return count

# Ejemplos
arr1 = [2, 2, 2, 2, 5, 5, 5, 8]
k1, threshold1 = 3, 4
print(numOfSubarrays(arr1, k1, threshold1))  # Salida: 3

arr2 = [11, 13, 17, 23, 29, 31, 7, 5, 2, 3]
k2, threshold2 = 3, 5
print(numOfSubarrays(arr2, k2, threshold2))  # Salida: 6
