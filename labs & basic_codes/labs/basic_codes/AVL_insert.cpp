Node *insert(Node *node, int key)
{
  // 1. 普通 BST insertion
  if (node == NULL)
    return new Node(key);

  if (key < node->key)
    node->left = insert(node->left, key);

  else if (key > node->key)
    node->right = insert(node->right, key);

  else
    return node; // 不插入重复 key

  // 2. 更新当前节点高度
  updateHeight(node);

  // 3. 看当前节点是否失衡
  int bf = getBalance(node);

  // LL
  if (bf > 1 && key < node->left->key)
    return rotateRight(node);

  // RR
  if (bf < -1 && key > node->right->key)
    return rotateLeft(node);

  // LR
  if (bf > 1 && key > node->left->key)
  {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }

  // RL
  if (bf < -1 && key < node->right->key)
  {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }

  // 本来就平衡
  return node;
}