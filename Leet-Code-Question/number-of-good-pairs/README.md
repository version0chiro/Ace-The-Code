[Discussion Post (created on 30/3/2021 at 19:40)](https://leetcode.com/problems/number-of-good-pairs/discuss/1184071/C%2B%2B-100-faster-solution-using-map)  
<h2>1512. Number of Good Pairs</h2><h3>Easy</h3><hr><div><p>Given an array of integers&nbsp;<code>nums</code>.</p>

<p>A pair&nbsp;<code>(i,j)</code>&nbsp;is called <em>good</em> if&nbsp;<code>nums[i]</code> == <code>nums[j]</code> and <code>i</code> &lt; <code>j</code>.</p>

<p>Return the number of <em>good</em> pairs.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1,1,3]
<strong>Output:</strong> 4
<strong>Explanation: </strong>There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1]
<strong>Output:</strong> 6
<strong>Explanation: </strong>Each pair in the array are <em>good</em>.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul></div>