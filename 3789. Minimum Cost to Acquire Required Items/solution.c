long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

  long long totalCost = 0;
  long long boughtBoth = 0;

  long long needRemaining;
  long long costRemaining;

  /* Buy both types equally until one requirement is satisfied */
  if(need1 > 0 && need2 > 0)
  {
    /* Determine the maximum amount both types need */
    boughtBoth = need1 < need2 ? need1 : need2; // Just the minimum

    /* Determine optimal purchasing method */
    if(cost1 + cost2 < costBoth) // Individually
    {
      totalCost += boughtBoth * (cost1 + cost2);
    }
    else // Together
    {
      totalCost += boughtBoth * costBoth;
    }
  }

  /* Determine remaining type needed */
  if(need1 > boughtBoth) // More of type 1
  {
    needRemaining = need1 - boughtBoth;
    costRemaining = cost1;
  }
  else // More of type 2
  {
    needRemaining = need2 - boughtBoth;
    costRemaining = cost2;
  }

  /* Buy remaining type - with optimal purchasing method*/
  if(costRemaining < costBoth) // Just the remaining type
  {
    totalCost += costRemaining * needRemaining;
  }
  else // Cheaper to buy both (only for remaining type)
  {
    totalCost += costBoth * needRemaining;
  }

  return totalCost;
}