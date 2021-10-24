public class Main {

    public static void main(String[] args) {
        Tree tree = new Tree();
        tree.insert(25);
        tree.insert(10);
        tree.insert(27);
        tree.insert(30);
        tree.insert(29);
        tree.insert(22);
        tree.insert(32);

//        tree.inOrderTraverse();
//        System.out.println(tree.get(10));
        System.out.println(tree.min());
    }
}
class Tree {

    private TreeNode root;

    public void insert(int value) {
        if (root == null) {
            root = new TreeNode(value);
        } else {
            root.insert(value);
        }
    }

    public TreeNode get(int value) {
        if (root != null)
            return root.get(value);
        return null;
    }
    // deleting
    // case 1: delete node is a leaf node
    // case 2: delete node has a only 1 child
    // case 3: delete node has a 2 child

    public void delete(int value) {
        root = delete(root, value);
    }

    private TreeNode delete(TreeNode subtreeRoot, int value) {

        if (subtreeRoot == null)
            return subtreeRoot;//check null and return null

        if (value < subtreeRoot.getData())
            subtreeRoot.setLeftChild(delete(subtreeRoot.getLeftChild(), value));

        else if (value > subtreeRoot.getData())
            subtreeRoot.setRightChild(delete(subtreeRoot.getRightChild(), value));

        else {  // value = subtreeRoot.getData()
            //case 1 & 2

            if (subtreeRoot.getLeftChild() == null)
                return subtreeRoot.getRightChild();
            else if (subtreeRoot.getRightChild() == null)
                return subtreeRoot.getLeftChild();

            // case 3 : node with 2 children
            // replace value with smallest value from right sub tree
            subtreeRoot.setData(subtreeRoot.getRightChild().min());

            // delete the node smallest value from right sub tree
            subtreeRoot.setRightChild(delete(subtreeRoot.getRightChild(), subtreeRoot.getData()));
        }
        return subtreeRoot;
    }


    public int min() {
        if (root == null)
            return Integer.MIN_VALUE;
        else
            return root.min();
    }

    public int max() {
        if (root == null)
            return Integer.MAX_VALUE;
        else
            return root.max();
    }

    public void inOrderTraverse() {
        if (root != null)
            root.inOrderTraverse();
    }
}
class TreeNode {
    private int data;
    private TreeNode leftChild;
    private TreeNode rightChild;

    public TreeNode(int data) {
        this.data = data;
    }

    public void insert(int value) {   // first check left is null or having child.if null assign or not recursively call that node's insert method
        if (value == data) //no allow duplicate values
            return;
        if (value < data) {
            if (leftChild == null) {
                leftChild = new TreeNode(value);
            } else {
                leftChild.insert(value);
            }
        } else {
            if (rightChild == null) {
                rightChild = new TreeNode(value);
            } else {
                rightChild.insert(value);
            }
        }

    }

    public TreeNode get(int value) {
        if (value == data)
            return this;
        if (value < data) {
            if (leftChild != null)
                return leftChild.get(value);
        } else {
            if (rightChild != null)
                return rightChild.get(value);
        }
        return null;
    }

    public int min() {
        if (leftChild == null)
            return data;
        else
            return leftChild.min();
    }

    public int max() {
        if (rightChild == null)
            return data;
        else
            return rightChild.max();
    }


    public void inOrderTraverse() {
        if (leftChild != null)
            leftChild.inOrderTraverse();
        System.out.print("Data = " + data + " ,");

        if (rightChild != null)
            rightChild.inOrderTraverse();

    }


    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public TreeNode getLeftChild() {
        return leftChild;
    }

    public void setLeftChild(TreeNode leftChild) {
        this.leftChild = leftChild;
    }

    public TreeNode getRightChild() {
        return rightChild;
    }

    public void setRightChild(TreeNode rightChild) {
        this.rightChild = rightChild;
    }

    @Override
    public String toString() {
        return "Data = " + data;
    }
}

