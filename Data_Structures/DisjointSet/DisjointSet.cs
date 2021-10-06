using System;
using System.Collections.Generic;
using System.Linq;

class DisjointSet
{
    /* Element is the new type, in this code Element can hold values of type double but it can be changed to hold any type.*/
    class Element
    {
        /* attributes are private they can be manupilated by the Getters and the Setters.*/
        private Element parent = null;

        private double value;

        private List<Element> childs = new List<Element>();

        public Element(double value)
        {
            this.value = value;
        }

        public Element getParent()
        {
            return this.parent;
        }

        public void setParent(Element newParent)
        {
            this.parent = newParent;
        }

        public double getValue()
        {
            return this.value;
        }

        public void setValue(double newValue)
        {
            this.value = newValue;
        }

        public Element[] getChilds()
        {
            return this.childs.ToArray();
        }

        public void addChild(Element child)
        {
            this.childs.Add(child);
        }
    }

    /* Method oneRoot checks if two elements have the same roor and returns a boolean value. */
    private static bool oneRoot(Element e1, Element e2)
    {
        return findRoot(e1) == findRoot(e2);
    }

    /* Method findRoot returns the root of an Element. */
    private static Element findRoot(Element e)
    {
        Element parent = e.getParent();
        return parent == null ? e : findRoot(parent);
    }

    /* Method union merges two Elements if they are from different roots and returns the root Element. */
    private static Element union(Element setRoot, Element setChild)
    {
        Element setRootRoot = findRoot(setRoot);
        Element setChildRoot = findRoot(setChild);
        if (setRootRoot != setChildRoot)
        {
            setChildRoot.setParent(setRoot);
            setRoot.addChild(setChild);
        }

        return setRootRoot;
    }

    /* Method rank returns the rank of an Element in the tree (rank(root) = 1). */
    private static double rank(Element e)
    {
        Element parent = e.getParent();
        return parent == null ? 1 : rank(parent) + 1;
    }

    /* Method depth returns the depth of the tree starting from the passed Element (depth(last Element) = 0) */
    private static double depth(Element e)
    {
        Element[] childs = e.getChilds();
        if (childs.Length == 0)
        {
            return 0;
        }
        else
        {
            double[] childsDepth = new double[childs.Length];

            for (int index = 0; index < childs.Length; index++)
            {
                childsDepth[index] = depth(childs[index]) + 1;
            }

            return childsDepth.Max();
        }
    }

    static void Main(string[] args)
    {
        //playground
        //creating some Elements
        Element a = new Element(0);
        Element b1 = new Element(1);
        Element b2 = new Element(2);
        Element c1 = new Element(3);
        Element c2 = new Element(4);
        Element c3 = new Element(4);
        Element d1 = new Element(5);
        Element d2 = new Element(6);
        Element e = new Element(7);
        Element f = new Element(8);

        //creating the hierarchy/tree
        c2 = union(c2, e);
        c1 = union(c1, d1);
        c1 = union(c1, d2);
        b1 = union(b1, c1);
        b1 = union(b1, c2);
        b1 = union(b1, c3);
        a = union(a, b1);
        a = union(a, b2);

        /* let's explore the Element b1 */
        /* first, some info about b1 */
        System
            .Console
            .WriteLine("---- b1 ----\nparent:{0}\nvalue:{1}\nnumber of childrens:{2}\n------------",
            b1.getParent().getValue(),
            b1.getValue(),
            b1.getChilds().Length);

        /* let's change the value of a */
        a.setValue(100);
        System.Console.WriteLine("a's new value = {0}", a.getValue());

        /* let's get the depth of a (should be 3) */
        System.Console.WriteLine("depth of a = {0}", depth(a));

        /* rank of e should be 4 */
        System.Console.WriteLine("rank of e = {0}", rank(e));

        /* let's see if b1 and c2 have the same root */
        bool oneroot = oneRoot(b1, c2);
        String yesNo = oneroot ? "yes" : "no";
        System.Console.WriteLine("Do b1 and c1 have the same root: {0}", yesNo);

        /* let's see if e and f have the same root */
        oneroot = oneRoot(e, f);
        yesNo = oneroot ? "yes" : "no";
        System.Console.WriteLine("Do e and f have the same root: {0}", yesNo);
    }
}
