using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LegacyCode
{
    class Program
    {
        static void Main(string[] args)
        {
            var order = new Tuple<string, List<Product>>("John Doe",
                new List<Product>
                {
                    new Product
                    {
                        ProductName = "Pulled Pork",
                        Price = 6.99m,
                        Weight = 0.5m,
                        PricingMethod = "PerPound",
                    },
                    new Product
                    {
                        ProductName = "Coke",
                        Price = 3m,
                        Quantity = 2,
                        PricingMethod = "PerItem"
                    }
                }
            );

            var price = 0m;
            var orderSummary = "ORDER SUMMARY FOR " + order.Item1 + ": \r\n";

            foreach (var orderProduct in order.Item2)
            {
                var productPrice = 0m;
                orderSummary += orderProduct.ProductName;

                if (orderProduct.PricingMethod == "PerPound")
                {
                    productPrice = (orderProduct.Weight.Value * orderProduct.Price);
                    price += productPrice;
                    orderSummary += (" $" + productPrice + " (" + orderProduct.Weight + " pounds at $" + orderProduct.Price + " per pound)");
                }
                else // Per item
                {
                    productPrice = (orderProduct.Quantity.Value * orderProduct.Price);
                    price += productPrice;
                    orderSummary += (" $" + productPrice + " (" + orderProduct.Quantity + " items at $" + orderProduct.Price + " each)");
                }

                orderSummary += "\r\n";
            }

            Console.WriteLine(orderSummary);
            Console.WriteLine("Total Price: $" + price);

            Console.ReadKey();
        }
    }

    public class Product
    {
        public string ProductName;
        public decimal Price;
        public decimal? Weight;
        public int? Quantity;
        public string PricingMethod;
    }
}
