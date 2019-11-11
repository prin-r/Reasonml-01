open Css;

let rec map = (arr, f) =>
  switch (arr) {
  | [] => []
  | [x, ...xs] => [f(x), ...map(xs, f)]
  };

[@react.component]
let make = (~orders, ~close) => {
  <div className={style([display(`flex), flexDirection(`column)])}>
    {orders
     ->map(title => <Order key=title title close />)
     ->Belt_List.toArray
     ->React.array}
  </div>;
};