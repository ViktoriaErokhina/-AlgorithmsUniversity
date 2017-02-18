#!/bin/bash
        for i in `seq 1 10`;
        do
        		./gen
				./your_solution
				diff output.txt brute_output.txt
                echo $i
        done    