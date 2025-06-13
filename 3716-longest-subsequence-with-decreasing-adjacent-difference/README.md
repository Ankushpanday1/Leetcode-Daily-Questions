<h2><a href="https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference">Longest Subsequence With Decreasing Adjacent Difference</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an array of integers <code>nums</code>.</p>

<p>Your task is to find the length of the <strong>longest subsequence</strong> <code>seq</code> of <code>nums</code>, such that the <strong>absolute differences</strong> between<em> consecutive</em> elements form a <strong>non-increasing sequence</strong> of integers. In other words, for a subsequence <code>seq<sub>0</sub></code>, <code>seq<sub>1</sub></code>, <code>seq<sub>2</sub></code>, ..., <code>seq<sub>m</sub></code> of <code>nums</code>, <code>|seq<sub>1</sub> - seq<sub>0</sub>| &gt;= |seq<sub>2</sub> - seq<sub>1</sub>| &gt;= ... &gt;= |seq<sub>m</sub> - seq<sub>m - 1</sub>|</code>.</p>

<p>Return the length of such a subsequence.</p>

<p>A <strong>subsequence</strong> is an <b>non-empty</b> array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [16,6,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong>&nbsp;</p>

<p>The longest subsequence is <code>[16, 6, 3]</code> with the absolute adjacent differences <code>[10, 3]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [6,5,3,4,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The longest subsequence is <code>[6, 4, 2, 1]</code> with the absolute adjacent differences <code>[2, 2, 1]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [10,20,10,19,10,20]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong>&nbsp;</p>

<p>The longest subsequence is <code>[10, 20, 10, 19, 10]</code> with the absolute adjacent differences <code>[10, 10, 9, 9]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 300</code></li>
</ul>
