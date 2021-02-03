package A202012;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.concurrent.DelayQueue;

public class Candidate {
	private static int N,M; // 사진틀 / 추천 횟수
	private static int input;
	private static int end;
	private static int[] stu;
	private static int cnt = 1000;
	private static Deque<Integer> q;
	private static Stack<Integer> s;
	public static void main(String[] args) throws Exception{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(bf.readLine());
		M = Integer.parseInt(bf.readLine());
		stu = new int[101];
		st = new StringTokenizer(bf.readLine());
		q = new LinkedList<>();
		s = new Stack<>();
		for(int i = 1; i <= M; ++i) {
			input = Integer.parseInt(st.nextToken());
			if(q.size() != N) {
				if(stu[input] == 0) {
					q.add(input);
				}
				stu[input]++;
				
			}
			else {
				cnt = 1000;
				if(stu[input] == 0) {
					for(int j = 0; j < N; ++j) {
						int t = q.poll();
						cnt = cnt > stu[t] ? stu[t] : cnt;
						q.add(t);
					}
					while(stu[q.peek()] != cnt) {
						s.add(q.poll());
					}
					stu[q.poll()] = 0;
					while(!s.isEmpty()) {
						q.addFirst(s.pop());
					}
					q.add(input);
				}
				stu[input]++;
			}
		}
		for(int i = 1; i <= 100; ++i) {
			if(stu[i] > 0) System.out.print(i + " ");
		}
	}

}
