def maximum_sum_subarray(arr, constraint):

    if not arr:

        print("No feasible subarray")

        return

    def max_cross_sum(arr, mid):

        left_sum = -999999

        s = 0

        left_index = mid

        for i in range(mid, -1, -1):

            s += arr[i]

            if s > left_sum:

                left_sum = s

                left_index = i

        right_sum = -999999

        s = 0

        right_index = mid + 1

        for i in range(mid + 1, len(arr)):

            s += arr[i]

            if s > right_sum:

                right_sum = s

                right_index = i

        cross_sum = left_sum + right_sum

        print("Left Sum:", left_sum, "Right Sum:", right_sum, "Cross Sum:", cross_sum)

        return cross_sum, arr[left_index:right_index + 1]


    def divide(arr):

        if len(arr) == 1:

            if arr[0] <= constraint:

                return arr[0], arr

            else:

                return -999999, []

        mid = len(arr) // 2

        left_sum, left_subarray = divide(arr[:mid])

        right_sum, right_subarray = divide(arr[mid:])

        cross_sum, cross_subarray = max_cross_sum(arr, mid - 1)

        max_sum = left_sum

        max_subarray = left_subarray

        if right_sum > max_sum:

            max_sum, max_subarray = right_sum, right_subarray

        if cross_sum > max_sum:

            max_sum, max_subarray = cross_sum, cross_subarray

        if max_sum > constraint:

            return -999999, []

        return max_sum, max_subarray

    max_sum, max_subarray = divide(arr)

    if max_sum <= 0:

        print("No feasible subarray")

    else:

        print("Maximum Sum:", max_sum)

        print("Subarray:", max_subarray)

print("Test 1:"); maximum_sum_subarray([2, 1, 3, 4], 5)

print("Test 2:"); maximum_sum_subarray([2, 2, 2, 2], 4)

print("Test 3:"); maximum_sum_subarray([1, 5, 2, 3], 5)

print("Test 4:"); maximum_sum_subarray([6, 7, 8], 5)

print("Test 5:"); maximum_sum_subarray([1, 2, 3, 2, 1], 5)

print("Test 6:"); maximum_sum_subarray([1, 1, 1, 1, 1], 4)

print("Test 7:"); maximum_sum_subarray([4, 2, 3, 1], 5)

print("Test 8:"); maximum_sum_subarray([], 10)

print("Test 9:"); maximum_sum_subarray([1, 2, 3], 0)

print("Test 10:"); maximum_sum_subarray(list(range(1, 21)), 50)

