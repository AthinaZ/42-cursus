#ifndef TREE_ALGO_HPP
#define TREE_ALGO_HPP


namespace ft
{
	/******** TREE ALGORITHM ********/
	/* ADAPTED FROM:
	https://opensource.apple.com/source/libcpp/libcpp-19/include/__tree.auto.html
	https://android.googlesource.com/platform/prebuilts/clang/darwin-x86/sdk/3.5/+/refs/heads/emu-1.5-release/include/c++/v1/__tree */

	template <class NodePtr>
	bool
	is_left_child(NodePtr x)
	{
		if (x->parent == nullptr || x == x->parent->left || (x->parent->left == nullptr && x != x->parent->right && x->parent->right != nullptr) )
			return true;
		return false;
	}

	template <class NodePtr>
	NodePtr tree_min(NodePtr x)
	{
		while (x->left != nullptr)
			x = x->left;
		return x;
	}

	template <class NodePtr>
	NodePtr tree_max(NodePtr x)
	{
		while (x->right != nullptr)
			x = x->right;
		return x;
	}

	template <class NodePtr>
	NodePtr tree_next(NodePtr x)
	{
		if (x->right != nullptr)
			return tree_min(x->right);
		while (!is_left_child(x))
			x = x->parent;
		return static_cast< NodePtr>(x->parent);
	}

	template <class NodePtr>
	NodePtr tree_prev(NodePtr x)
	{
		if (x->left != nullptr)
			return tree_max(x->left);
		while (x->parent != nullptr && is_left_child(x))
			x = x->parent;
		if (x->parent == nullptr)
			return x;
		return x->parent;
	}

	template <class NodePtr>
	void
	left_rotate(NodePtr x)
	{
		NodePtr y = x->right;
		x->right = y->left;
		if (x->right != nullptr)
			x->right->parent = x;
		y->parent = x->parent;
		if (is_left_child(x))
		{
			if (x->parent != nullptr)
				x->parent->left = y;
		}
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	template <class NodePtr>
	void
	right_rotate(NodePtr x)
	{
		NodePtr y = x->left;
		x->left = y->right;
		if (x->left != nullptr)
			x->left->parent = x;
		y->parent = x->parent;
		if (is_left_child(x))
		{
			if (x->parent != nullptr)
				x->parent->left = y;
		}
		else
			x->parent->right = y;
		y->right = x;
		x->parent = y;
	}

	template <class NodePtr>
	void
	balance_after_insert(NodePtr root, NodePtr x)
	{
		while (x != root && !x->parent->is_black)
		{
			if (is_left_child(x->parent))
			{
				NodePtr y = x->parent->parent->right;
				if (y != nullptr && !y->is_black && !y->is_end)
				{
					x = x->parent;
					x->is_black = true;
					x = x->parent;
					x->is_black = x == root;
					y->is_black = true;
				}
				else
				{
					if (!is_left_child(x))
					{
						x = x->parent;
						left_rotate(x);
					}
					x = x->parent;
					x->is_black = true;
					x = x->parent;
					x->is_black = false;
					right_rotate(x);
					break;
				}
			}
			else
			{
				NodePtr y = x->parent->parent->left;
				if (y != nullptr && !y->is_black)
				{
					x = x->parent;
					x->is_black = true;
					x = x->parent;
					x->is_black = x == root;
					y->is_black = true;
				}
				else
				{
					if (is_left_child(x))
					{
						x = x->parent;
						right_rotate(x);
					}
					x = x->parent;
					x->is_black = true;
					x = x->parent;
					x->is_black = false;
					left_rotate(x);
					break;
				}
			}
		}
	}

	template <class NodePtr>
	void
	tree_remove(NodePtr root, NodePtr z)
	{
		NodePtr y = (z->left == nullptr ||  z->right == nullptr || (z->right->is_end)) ? z : tree_next(z);
		NodePtr x = y->left != nullptr ? y->left : y->right;
		if (x != nullptr && x->is_end)
			x = nullptr;
		NodePtr w = nullptr;
		if (x != nullptr)
			x->parent = y->parent;
		if (is_left_child(y))
		{
			if (root != y)
				y->parent->left = x;
			if (y != root)
				w = y->parent->right;
			else
				root = x;
		}
		else
		{
			y->parent->right = x;
			w = y->parent->left;
		}
		bool removed_black = y->is_black;
		if (y != z)
		{
			y->parent = z->parent;
			if (is_left_child(z))
			{
				if (root == z)
					root = y;
				else
					y->parent->left = y;
			}
			else
				y->parent->right = y;
			y->left = z->left;
			y->left->parent = y;
			y->right = z->right;
			if (y->right != nullptr)
				y->right->parent = y;
			y->is_black = z->is_black;
		}
		if (removed_black && root != nullptr)
		{
			if (x != nullptr)
				x->is_black = true;
			else
			{
				while (true)
				{
					if (!is_left_child(w))
					{
						if (!w->is_black)
						{
							w->is_black = true;
							w->parent->is_black = false;
							left_rotate(w->parent);
							if (root == w->left)
								root = w;
							w = w->left->right;
						}
						if ((w->left  == nullptr || w->left->is_black) && (w->right == nullptr || w->right->is_black))
						{
							w->is_black = false;
							x = w->parent;
							if (x == root || !x->is_black)
							{
								x->is_black = true;
								break;
							}
							w = is_left_child(x) ?
										x->parent->right :
										x->parent->left;
						}
						else
						{
							if (w->right == nullptr || w->right->is_black)
							{
								w->left->is_black = true;
								w->is_black = false;
								right_rotate(w);
								w = w->parent;
							}
							w->is_black = w->parent->is_black;
							w->parent->is_black = true;
							w->right->is_black = true;
							left_rotate(w->parent);
							break;
						}
					}
					else
					{
						if (!w->is_black)
						{
							w->is_black = true;
							w->parent->is_black = false;
							right_rotate(w->parent);
							if (root == w->right)
								root = w;
							w = w->right->left;
						}
						if ((w->left  == nullptr || w->left->is_black) &&
							(w->right == nullptr || w->right->is_black))
						{
							w->is_black = false;
							x = w->parent;
							if (!x->is_black || x == root)
							{
								x->is_black = true;
								break;
							}
							w = is_left_child(x) ?
										x->parent->right :
										x->parent->left;
						}
						else
						{
							if (w->left == nullptr || w->left->is_black)
							{
								w->right->is_black = true;
								w->is_black = false;
								left_rotate(w);
								w = w->parent;
							}
							w->is_black = w->parent->is_black;
							w->parent->is_black = true;
							w->left->is_black = true;
							right_rotate(w->parent);
							break;
						}
					}
				}
			}
		}
	}
}

#endif
